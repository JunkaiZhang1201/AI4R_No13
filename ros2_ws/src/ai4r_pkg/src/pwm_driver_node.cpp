#include "ai4r_pkg/pwm_driver_node.hpp"
#include "ai4r_pkg/topic_names.hpp"

// Static Global Variables
static uint16_t steering_set_point = STEERING_NEUTRAL_PULSE_WIDTH;
static uint16_t last_steering_command = STEERING_NEUTRAL_PULSE_WIDTH;
static uint16_t esc_set_point = ESC_NEUTRAL_PULSE_WIDTH;

class PwmDriverNode : public rclcpp::Node {
    public:
        PwmDriverNode() : Node("pwm_driver_node") {
            servo_pulse_width_sub_ = this->create_subscription<ai4r_interfaces::msg::ServoPulseWidth>(
                SERVO_PW, rclcpp::QoS(10), std::bind(&PwmDriverNode::servoSubscriberCallback, this, std::placeholders::_1)
            );

            timer_ = this->create_wall_timer(100ms, std::bind(&PwmDriverNode::timer_callback, this));

            // Open the I2C device
            // > Note that the I2C driver is already instantiated
            //   as a member variable of this node
            bool open_success = m_i2c_driver.open_i2c_device();

            // Display the status
            if (!open_success) {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] FAILED to open I2C device named " << m_i2c_driver.get_device_name());
            } else {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] Successfully opened named " << m_i2c_driver.get_device_name() << ", with file descriptor = " << m_i2c_driver.get_file_descriptor());
            }

            // SET THE CONFIGURATION OF THE SERVO DRIVER

            // Specify the frequency of the servo driver -> default for this is 200 Hz
            float new_frequency_in_hz = SERVO_FREQUENCY;
            bool verbose_display_for_servo_driver_init = false;
            
            // Call the Servo Driver initialisation function
            bool result_servo_init = m_pca9685_servo_driver.initialise_with_frequency_in_hz(new_frequency_in_hz, verbose_display_for_servo_driver_init);
            
            // Report Servo Board Initialisation Result
            if (!result_servo_init)	{
                RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] FAILED - while initialising servo driver with I2C address " << static_cast<int>(m_pca9685_servo_driver.get_i2c_address()) );
            } else {
                RCLCPP_INFO_STREAM(this->get_logger(), "[PWM DRIVER NODE] SUCCESS - while initialising servo driver with I2C address " << static_cast<int>(m_pca9685_servo_driver.get_i2c_address()) );
            }
        }

    private:
        // Send a pulse width on the specified channel.
        void setPWMSignal(uint8_t channel, uint16_t pulse_width_in_us) {
            // Call the function to set the desired pulse width
            bool result = m_pca9685_servo_driver.set_pwm_pulse_in_microseconds(channel, pulse_width_in_us);

            // Display if an error occurred
            if (!result) {
                RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] FAILED to set pulse width for servo at channel " << static_cast<int>(channel) );
            }
        }

        // Set the pwm value according to the set point for each servo
        //void setSteeringPulseWidth();
        //void setEscPulseWidth();

        // Convert the percentage command to a pwm pulse width.
        //uint16_t percentageToPulseWidth(float value);

        void timer_callback() {
   
        }

        void servoSubscriberCallback(const ai4r_interfaces::msg::ServoPulseWidth & msg) {
            // Extract the channel and pulse width from the message
            uint16_t channel = msg.channel;
            uint16_t pulse_width_in_us = msg.pulse_width_in_microseconds;

            // Display the message received
            RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] Message received for servo with channel = " << static_cast<int>(channel) << ", and pulse width [us] = " << static_cast<int>(pulse_width_in_us) );

            // Limit the pulse width to be either:
            // > zero
            // > in the range [1000,2000]
            if (pulse_width_in_us > 0) {
                if (pulse_width_in_us < 1000)
                    pulse_width_in_us = 1000;
                if (pulse_width_in_us > 2000)
                    pulse_width_in_us = 2000;
            }

            // Set servo PWM signal to this value
            setPWMSignal(channel, pulse_width_in_us);

            // Save the set value
            if(channel == 0) {
                last_steering_command = pulse_width_in_us;
                steering_set_point = pulse_width_in_us;
            } else if(channel == 1) {
                esc_set_point = pulse_width_in_us;
            }
        }

        rclcpp::TimerBase::SharedPtr timer_;

        rclcpp::Subscription<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr servo_pulse_width_sub_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PwmDriverNode>();
    rclcpp::spin(node); // Use rclcpp::spin() to handle callbacks.

	// Close the I2C device
	bool close_success = m_i2c_driver.close_i2c_device();
	
	// Display the status
	if (!close_success) {
		RCLCPP_INFO_STREAM(node->get_logger(), "[TEMPLATE I2C INTERNAL] FAILED to close I2C device named " << m_i2c_driver.get_device_name());
	} else {
		RCLCPP_INFO_STREAM(node->get_logger(), "[TEMPLATE I2C INTERNAL] Successfully closed device named " << m_i2c_driver.get_device_name());
	}
    
    rclcpp::shutdown();
    return 0;
}
