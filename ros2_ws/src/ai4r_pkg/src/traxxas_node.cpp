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
            steering_set_point_percent_sub_ = this->create_subscription<std_msgs::msg::Float32>(
                STEERING_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::steeringSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            );
            esc_set_point_percent_sub_ = this->create_subscription<std_msgs::msg::Float32>(
                ESC_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::escSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            );
            esc_and_steering_set_point_percent_sub_ = this->create_subscription<ai4r_interfaces::msg::EscAndSteering>(
                ESC_AND_STEERING_SET_POINT_PERCENT, rclcpp::QoS(10), std::bind(&TraxxasNode::escAndSteeringSetPointPercentSubscriberCallback, this, std::placeholders::_1)
            );
            estop_sub_ = this->create_subscription<std_msgs::msg::UInt16>(
                ESTOP, rclcpp::QoS(10), std::bind(&TraxxasNode::estopSubscriberCallback, this, std::placeholders::_1)
            );

            // 100 Hz (same rate as servo board)
            timer_ = this->create_wall_timer(10ms, std::bind(&TraxxasNode::timer_callback, this));

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
                RCLCPP_INFO_STREAM(this->get_logger(), "[TRAXXAS NODE] SUCCESS - while initialising servo driver with I2C address " << static_cast<int>(m_pca9685_servo_driver.get_i2c_address()) );
            }
        }

    private:
        // Private variables 
        State currentState = State::Enabled;    // State initially Enabled
        int estop = ENABLE; // Store last estop command (initially ENABLE)
        int esc_empty_msg_count = 0;    // Counter to store number of empty message cycles for esc
        int steering_empty_msg_count = 0;   // Counter to store number of empty message cycles for steering

        // Traxxas node synchronous FSM: Periodically called at regular time intervals to trigger state transitions 
        // Moore machine implementation: outputs only based on the current state of the machine, regardless of the input
        void timer_callback() {
            // State transitions first
            switch (currentState) {
                case State::Enabled:
                    if (estop == DISABLE) {
                        currentState = State::Disabled;
                        RCLCPP_INFO_STREAM(this->get_logger(), "Disabled directly" );
                    } 
                    if (esc_empty_msg_count > MIN_EMPTY_MSG_CYCLES_TO_TIMEOUT) {
                        currentState = State::Disabled;
                        RCLCPP_INFO_STREAM(this->get_logger(), "Disabled because ESC channel timed out: Waited " << static_cast<int>(MIN_EMPTY_MSG_CYCLES_TO_TIMEOUT) << " cycles and no message received");
                    }
                    if (steering_empty_msg_count > MIN_EMPTY_MSG_CYCLES_TO_TIMEOUT) {
                        currentState = State::Disabled;
                        RCLCPP_INFO_STREAM(this->get_logger(), "Disabled because steering channel timed out: Waited " << static_cast<int>(MIN_EMPTY_MSG_CYCLES_TO_TIMEOUT) << " cycles and no message received");
                    }
                    // if (object_detected)
                    break;
                case State::Disabled:
                    if (estop == ENABLE) {
                        RCLCPP_INFO_STREAM(this->get_logger(), "Attempting to enable" );
                        if (esc_set_point == ESC_NEUTRAL_PULSE_WIDTH) {
                            RCLCPP_INFO_STREAM(this->get_logger(), "ESC is set to neutral: safe to enable" );
                            currentState = State::Enabled;
                        } else {
                            RCLCPP_INFO_STREAM(this->get_logger(), "ESC is NOT set to neutral: please set to neutral first before enabling" );
                        }
                    }
                    break;
            }

            // Then enact resulting state behaviour
            switch (currentState) {
                case State::Enabled:
                    RCLCPP_INFO_STREAM(this->get_logger(), "ENABLED" );
                    // Send messages to the motors
                    setSteeringPulseWidth();
                    setEscPulseWidth();
                    break;
                case State::Disabled:
                    RCLCPP_INFO_STREAM(this->get_logger(), "DISABLED" );
                    // Stop ESC motor and return steering to centre position
                    setPWMSignal(STEERING_SERVO_CHANNEL, STEERING_NEUTRAL_PULSE_WIDTH);
                    setPWMSignal(ESC_SERVO_CHANNEL, ESC_NEUTRAL_PULSE_WIDTH);
                    // Also set esc and steering back to neutral position
                    esc_set_point = ESC_NEUTRAL_PULSE_WIDTH;
                    steering_set_point = STEERING_NEUTRAL_PULSE_WIDTH;
                    // Also reset the counters
                    steering_empty_msg_count = 0;   // Message received so reset counter to 0
                    esc_empty_msg_count = 0;    // Message received so reset counter to 0
                    break;
            }

            // Only if wheels are spinning, increment the timeout counters
            if (esc_set_point != ESC_NEUTRAL_PULSE_WIDTH) {
                // Increment counters
                esc_empty_msg_count++;
                steering_empty_msg_count++;
            }
        }

        // Send a pulse width on the specified channel.
        void setPWMSignal(uint16_t channel, uint16_t pulse_width_in_us) {
            // Call the function to set the desired pulse width
            bool result = m_pca9685_servo_driver.set_pwm_pulse_in_microseconds(channel, pulse_width_in_us);

            // Display if an error occurred
            if (!result) {
                //RCLCPP_INFO_STREAM(this->get_logger(), "[TEMPLATE I2C INTERNAL] FAILED to set pulse width for servo at channel " << static_cast<int>(channel) );
            }
        }

        // Convert percentage to PWM
        uint16_t percentageToPulseWidth(float value) {
            uint16_t pulse_width;

            if(value <= -100.0) {
                pulse_width = MINIMUM_PULSE_WIDTH;
            } else if(value >= 100.0) {
                pulse_width = MAXIMUM_PULSE_WIDTH;
            } else {
                // Basic equation to convert between two ranges. Idea is add fraction of total range to the minimum value.
                float float_in_range = MINIMUM_PULSE_WIDTH + (MAXIMUM_PULSE_WIDTH - MINIMUM_PULSE_WIDTH)*((value + 100)/200.0);
                
                // Convert from float to integer
                pulse_width = static_cast<uint16_t>(lrintf32(float_in_range));
            }

            return pulse_width;
        }

        // Send steering servo to PWM set point incrementally
        void setSteeringPulseWidth() {
            // Read the most recent steering set point
            int value = steering_set_point;

            // See if this is greater than the defined steering step away from the
            // last value set to the steering servo. If it is, increment by the
            // step in the correct direction and send that. Otherwise send the set
            // point.
            if(abs(value - last_steering_command) > STEERING_PULSE_WIDTH_STEP) {
                if(value > last_steering_command) {
                    value = last_steering_command + STEERING_PULSE_WIDTH_STEP;
                } else {
                    value = last_steering_command - STEERING_PULSE_WIDTH_STEP;
                }
            }

            setPWMSignal(STEERING_SERVO_CHANNEL, value);
            last_steering_command = value;
        }

        // Send ESC to PWM set point directly
        void setEscPulseWidth() {
            // Directly send the ESC set point
            setPWMSignal(ESC_SERVO_CHANNEL, esc_set_point);
        }

        // For receiving PWM values to control the steering (channel 0) or esc (channel 1)
        void servoSubscriberCallback(const ai4r_interfaces::msg::ServoPulseWidth & msg) {
            // Extract the channel and pulse width from the message
            uint16_t channel = msg.channel;
            uint16_t pulse_width_in_us = msg.pulse_width_in_microseconds;

            // Display the message received
            RCLCPP_INFO_STREAM(this->get_logger(), "Message received for servo with channel = " << static_cast<int>(channel) << ", and pulse width [us] = " << static_cast<int>(pulse_width_in_us) );

            // Limit the pulse width to be either:
            // > zero
            // > in the range [1000,2000]
            if (pulse_width_in_us > 0) {
                if (pulse_width_in_us < MINIMUM_PULSE_WIDTH)
                    pulse_width_in_us = MINIMUM_PULSE_WIDTH;
                if (pulse_width_in_us > MAXIMUM_PULSE_WIDTH)
                    pulse_width_in_us = MAXIMUM_PULSE_WIDTH;
            }

            // Set servo PWM signal to this value
            setPWMSignal(channel, pulse_width_in_us);

            // Save the set value
            if(channel == STEERING_SERVO_CHANNEL) {
                last_steering_command = pulse_width_in_us;
                steering_set_point = pulse_width_in_us;

                steering_empty_msg_count = 0;   // Message received so reset counter to 0
            } else if(channel == ESC_SERVO_CHANNEL) {
                esc_set_point = pulse_width_in_us;

                esc_empty_msg_count = 0;    // Message received so reset counter to 0
            }
        }

        // For receiving percentage values to control the steering (channel 0)
        void steeringSetPointPercentSubscriberCallback(const std_msgs::msg::Float32 & msg) {
            // Extract percent value
            float value = msg.data;

            // Convert to pulse width
            float new_value = percentageToPulseWidth(value);

            // Display the message received
            RCLCPP_INFO_STREAM(this->get_logger(), "Message received for steering servo (channel 0). Percentage command received = " << static_cast<float>(value) << ", PWM sent to motors = " << static_cast<float>(new_value) );
           
            // Save value as the set point
            steering_set_point = new_value;

            steering_empty_msg_count = 0;   // Message received so reset counter to 0
        }

        // For receiving percentage values to control the esc (channel 1)
        void escSetPointPercentSubscriberCallback(const std_msgs::msg::Float32 & msg) {
            // Extract percent value
            float value = msg.data;

            // Convert to pulse width
            float new_value = percentageToPulseWidth(value);

            // Display the message received
            RCLCPP_INFO_STREAM(this->get_logger(), "Message received for esc (channel 1). Percentage command received = " << static_cast<float>(value) << ", PWM sent to motors = " << static_cast<float>(new_value) );

            // Save value as the set point
            esc_set_point = new_value;

            esc_empty_msg_count = 0;    // Message received so reset counter to 0
        }

        // For receiving percentage values to control both the steering (channel 0) and esc (channel 1)
        void escAndSteeringSetPointPercentSubscriberCallback(const ai4r_interfaces::msg::EscAndSteering & msg) {
            // Convert to pulse width and save value as the set point
            steering_set_point = percentageToPulseWidth(msg.steering_percent);
            esc_set_point = percentageToPulseWidth(msg.esc_percent);

            // Display the message received
            RCLCPP_INFO_STREAM(this->get_logger(), "Message received for steering servo (channel 0). Percentage command received = " << static_cast<float>(msg.steering_percent) << ", PWM sent to motors = " << static_cast<float>(steering_set_point) );
            RCLCPP_INFO_STREAM(this->get_logger(), "Message received for esc (channel 1). Percentage command received = " << static_cast<float>(msg.esc_percent) << ", PWM sent to motors = " << static_cast<float>(esc_set_point) );

            steering_empty_msg_count = 0;   // Message received so reset counter to 0
            esc_empty_msg_count = 0;    // Message received so reset counter to 0
        }

        // For receiving estop commands
        void estopSubscriberCallback(const std_msgs::msg::UInt16 & msg) {
            // Extract estop command
            int command = msg.data;

            // Display the message received
            if (command == DISABLE) {
                RCLCPP_INFO_STREAM(this->get_logger(), "ESTOP pressed" );
                estop = DISABLE;
            } else if (command == ENABLE) {
                RCLCPP_INFO_STREAM(this->get_logger(), "ESTOP released" );
                estop = ENABLE;
            } else {
                RCLCPP_INFO_STREAM(this->get_logger(), "Invalid estop command" );
            }
        }


        rclcpp::TimerBase::SharedPtr timer_;

        rclcpp::Subscription<ai4r_interfaces::msg::ServoPulseWidth>::SharedPtr servo_pulse_width_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr steering_set_point_percent_sub_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr esc_set_point_percent_sub_;
        rclcpp::Subscription<ai4r_interfaces::msg::EscAndSteering>::SharedPtr esc_and_steering_set_point_percent_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt16>::SharedPtr estop_sub_;

};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TraxxasNode>();
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
