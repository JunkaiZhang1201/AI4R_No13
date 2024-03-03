
#include "ai4r_pkg/traxxas_node.hpp"
#include "ai4r_pkg/topic_names.hpp"

// Static Global Variables
static uint16_t steering_set_point = STEERING_NEUTRAL_PULSE_WIDTH;
static uint16_t last_steering_command = STEERING_NEUTRAL_PULSE_WIDTH;
static uint16_t esc_set_point = ESC_NEUTRAL_PULSE_WIDTH;

class TraxxasNode : public rclcpp::Node {
    public:
        TraxxasNode() : Node("traxxas_node") {
            servo_pulse_width_sub_ = this->create_subscription<ai4r_interfaces::msg::ServoPulseWidth>(
                SERVO_PW, rclcpp::QoS(10), std::bind(&TraxxasNode::servoSubscriberCallback, this, std::placeholders::_1)
            );
            select_pulse_width_sub_ = this->create_subscription<std_msgs::msg::Bool>(
                SELECT_PW, rclcpp::QoS(10), std::bind(&TraxxasNode::selectSubscriberCallback, this, std::placeholders::_1)
            );
            // steering_set_point_percent_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            //     STEERING_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::steeringSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            // );
            // esc_set_point_percent_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            //     ESC_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::escSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            // );
            // esc_and_steering_set_point_percent_sub_ = this->create_subscription<ai4r_interfaces::msg::EscAndSteering>(
            //     ESC_AND_STEERING_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::escAndSteeringSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            // );
            // estop_sub_ = this->create_subscription<std_msgs::msg::UInt16>(
            //     ESTOP, rclcpp::QoS(10), std::bind(&TraxxasNode::estopSubscriberCallback, this, std::placeholders::_1)
            // );
            // line_detector_timeout_sub_ = this->create_subscription<std_msgs::msg::Bool>(
            //     LINE_DETECTOR_TIMEOUT_FLAG, rclcpp::QoS(10), std::bind(&TraxxasNode::lineDetectorTimeoutCallback, this, std::placeholders::_1)
            // );

            // select_set_sub = this->create_subscription<ai4r_interfaces::msg::Ser

            // // Publisher for the FSM state
            // state_publisher_ = this->create_publisher<std_msgs::msg::String>("traxxas_state", 10);

            // Publisher for the current i2c commands
            current_esc_pulse_width_publisher_ = this->create_publisher<ai4r_interfaces::msg::ServoPulseWidth>("traxxas_esc_current_pulse_width", 10);
            current_steering_pulse_width_publisher_ = this->create_publisher<ai4r_interfaces::msg::ServoPulseWidth>("traxxas_steering_current_pulse_width", 10);

            // // 100 Hz (same rate as servo board)
            // timer_ = this->create_wall_timer(10ms, std::bind(&TraxxasNode::timer_callback, this));

            // Open the I2C device
            // > Note that the I2C driver is already instantiated
            //   as a member variable of this node
            bool open_success = m_i2c_driver.open_i2c_device();

            // Display the status
            if (!open_success) {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] FAILED to open I2C device named " << m_i2c_driver.get_device_name());
            } else {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] Successfully opened named " << m_i2c_driver.get_device_name() << ", with file descriptor = " << m_i2c_driver.get_file_descriptor());
            }

            // SET THE CONFIGURATION OF THE SERVO DRIVER

            // Specify the frequency of the servo driver -> default for this is 200 Hz
            float new_frequency_in_hz = SERVO_FREQUENCY;
            bool verbose_display_for_servo_driver_init = false;
            
            // Call the Servo Driver initialisation function
            bool result_servo_init = m_pca9685_servo_driver.initialise_with_frequency_in_hz(new_frequency_in_hz, verbose_display_for_servo_driver_init);
            
            // Report Servo Board Initialisation Result
            if (!result_servo_init)	{
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] FAILED - while initialising servo driver with I2C address " << static_cast<int>(m_pca9685_servo_driver.get_i2c_address()) );
            } else {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] SUCCESS - while initialising servo driver with I2C address " << static_cast<int>(m_pca9685_servo_driver.get_i2c_address()) );
            }
        }

    private:
        State currentState = State::Enabled;    // State initially Enabled
        int estop = ESTOP_ENABLE; // Store last estop command (initially ENABLE) possibly change to enab
        int esc_empty_msg_count = 0;    // Counter to store number of empty message cycles for esc
        int steering_empty_msg_count = 0;   // Counter to store number of empty message cycles for steering
        bool line_detector_timeout_flag = false;
        // Send a pulse width on the specified channel.
        void setPWMSignal(uint16_t channel, uint16_t pulse_width_in_us) {
            // Call the function to set the desired pulse width
            bool result = m_pca9685_servo_driver.set_pwm_pulse_in_microseconds(channel, pulse_width_in_us);

            // Display if an error occurred
            if (!result) {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] FAILED to set pulse width for servo at channel " << static_cast<int>(channel) );
            }
            else{
                // Publish the value set
                if (channel == STEERING_SERVO_CHANNEL)
                {
                    auto message = ai4r_interfaces::msg::ServoPulseWidth();
                    message.channel = channel;
                    message.pulse_width_in_microseconds = pulse_width_in_us;
                    current_steering_pulse_width_publisher_->publish(message);
                }
                else if (channel == ESC_SERVO_CHANNEL)
                {
                    auto message = ai4r_interfaces::msg::ServoPulseWidth();
                    message.channel = channel;
                    message.pulse_width_in_microseconds = pulse_width_in_us;
                    current_esc_pulse_width_publisher_->publish(message);
                }

            }
        }

        // For receiving PWM values to control the steering (channel 0) or esc (channel 1)
        void selectSubscriberCallback(const std_msgs::msg::Bool & msg) {
            // Extract the channel and pulse width from the message
            bool enable_sel = msg.data;

            // Display the message received
            //RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] Message received for servo with channel = " << static_cast<int>(channel) << ", and pulse width [us] = " << static_cast<int>(pulse_width_in_us) );

            // Limit the pulse width to be either:
            // > zero
            // > in the range [1000,2000]
            uint16_t pulse_width = 1000;
            if (enable_sel == true) {
              pulse_width = 2000;
            }
            else {
                pulse_width = 1000;
            }

            // Set servo PWM signal to this value
            setPWMSignal(12, pulse_width);
        }
        // For receiving PWM values to control the steering (channel 0) or esc (channel 1)
        void servoSubscriberCallback(const ai4r_interfaces::msg::ServoPulseWidth & msg) {
            // Extract the channel and pulse width from the message
            uint16_t channel = msg.channel;
            uint16_t pulse_width_in_us = msg.pulse_width_in_microseconds;

            // Display the message received
            //RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS] Message received for servo with channel = " << static_cast<int>(channel) << ", and pulse width [us] = " << static_cast<int>(pulse_width_in_us) );

            // Limit the pulse width to be either:
            // > zero
            // > in the range [1000,2000]

            if (pulse_width_in_us > 0) {
                if (pulse_width_in_us < MINIMUM_PULSE_WIDTH_ESC)
                    pulse_width_in_us = MINIMUM_PULSE_WIDTH_ESC;
                if (pulse_width_in_us > MAXIMUM_PULSE_WIDTH_ESC)
                    pulse_width_in_us = MAXIMUM_PULSE_WIDTH_ESC;
            }

            // Set servo PWM signal to this value
            setPWMSignal(channel, pulse_width_in_us);
            if (channel ==  ESC_SERVO_CHANNEL) {
                esc_set_point = pulse_width_in_us;

                esc_empty_msg_count = 0; 
            }
            else if (channel == STEERING_SERVO_CHANNEL) {
                last_steering_command = pulse_width_in_us;
                steering_set_point = pulse_width_in_us;

                steering_empty_msg_count = 0;   // Message received so reset counter to 0
            }

        }

        rclcpp::Subscription<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr servo_pulse_width_sub_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr select_pulse_width_sub_;
        rclcpp::Publisher<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr current_esc_pulse_width_publisher_;
        rclcpp::Publisher<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr current_steering_pulse_width_publisher_;

};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TraxxasNode>();
    rclcpp::spin(node); // Use rclcpp::spin() to handle callbacks.

	// Close the I2C device
	bool close_success = m_i2c_driver.close_i2c_device();
	
	// Display the status
	if (!close_success) {
		RCLCPP_INFO_STREAM(node->get_logger(), "[TRAXXAS] FAILED to close I2C device named " << m_i2c_driver.get_device_name());
	} else {
		RCLCPP_INFO_STREAM(node->get_logger(), "[TRAXXAS] Successfully closed device named " << m_i2c_driver.get_device_name());
	}
    
    rclcpp::shutdown();
    return 0;
}
