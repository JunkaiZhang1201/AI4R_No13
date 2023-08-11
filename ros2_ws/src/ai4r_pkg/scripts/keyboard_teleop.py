#!/usr/bin/env python3
import os
import signal
import sys

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_system_default
from pynput.keyboard import Key, Listener
from ai4r_interfaces.msg import EscAndSteering
from geometry_msgs.msg import Twist


class KeyboardTeleop(Node):
    def __init__(self):
        super().__init__("keyboard_teleop")

        self.declare_parameter("twist_stamped_enabled", False)
        self.declare_parameter("linear_max", 100)
        self.declare_parameter("angular_max", 100)
        self.declare_parameter("publish_rate", 10.0)

        self.LINEAR_MAX = self.get_parameter("linear_max").value

        self.ANGULAR_MAX = self.get_parameter("angular_max").value
        
        self.publisher_ = self.create_publisher(
                EscAndSteering, "esc_and_steering_set_point_percent", qos_profile_system_default
        )


        self._make_twist = self._make_twist_unstamped

        self.ang_steps = 10
        self.lin_steps = 10

        self.inc_ang = 0
        self.inc_lin = 0

        self.flag = False

        rate = 1 / self.get_parameter("publish_rate").value
        self.create_timer(rate, self._publish)
        self.linear = 0
        self.angular = 0

        self.key_listener = Listener(
            on_press=self.update_twist,
            on_release=self.on_release,
        )
        self.key_listener.start()

        self.keys_bindings = {
            "w": (50, 0),
            "s": (-50, 0),
            "a": (0, 20),
            "d": (0, -20),
        }
        self.special_keys_bindings = {
            Key.up: (50, 0),
            Key.down: (-50, 0),
            Key.left: (0,20),
            Key.right: (0, -20),
        }
        self.multipler_keys_bindings = {
            "i": (self.lin_steps, 0),
            "k": (-self.lin_steps, 0),
            "j": (0, self.ang_steps),
            "l": (0, -self.ang_steps),
        }

        self.get_logger().info(
            f"""
This node takes keypresses from the keyboard and publishes them 
as Twist messages. This is the incremental mode; every key press 
incrementally increase or decrease the respective dimensional speed.

WARNING: This node will take commands even if your terminal is not in focus!

Controls:

Arrows to increase/decrease speeds
IJKL to increase/decrease speeds multiplier
Any other key to stop
CTRL-C or q to quit

Configuration:

Increment per Linear keypress: {self.lin_steps} m/s or rad/s
Increment per Angular keypress: {self.ang_steps} m/s or rad/s
Max Linear Speed: +/-{self.LINEAR_MAX} m/s
Max Angular Speed: +/-{self.ANGULAR_MAX} rad/s
"""
        )

    def on_release(self, key):
        if self._is_special_key(key):

            if key in self.special_keys_bindings:
                if key == Key.up or key == Key.down:
                    self.write_twist(linear=0)
                elif key == Key.left or key == Key.right:
                    self.write_twist(angular=0)
        else:
            key = key.char
            if key in self.keys_bindings:
                if key == "w" or key == "s":
                    self.write_twist(linear=0)
                elif key == "a" or key == "d":
                    self.write_twist(angular=0)
            if key in self.multipler_keys_bindings:
                if key == "i" or key == "k":
                    self.inc_lin += self.multipler_keys_bindings[key][0]
                elif key == "j" or key == "l":
                    self.inc_ang += self.multipler_keys_bindings[key][1]

    def update_twist(self, key):
        binding = None
        binding2 = None
        if self._is_special_key(key):
            if key in self.special_keys_bindings:
                binding = self.special_keys_bindings[key]
            else:
                self.write_twist(0, 0)
        else:
            if key.char == "q":
                os.kill(os.getpid(), signal.SIGINT)
            if key.char in self.keys_bindings:
                binding = self.keys_bindings[key.char]
            if key.char in self.multipler_keys_bindings:
                binding2 = self.multipler_keys_bindings[key.char] 
            else:
                self.write_twist(0, 0)
        if binding is not None:
            if binding[0] == 0:
                new_linear = self.linear
                new_angular = binding[1] + self.inc_ang
            if binding[1] == 0:
                new_linear = binding[0] + self.inc_lin
                new_angular = self.angular 

            self.write_twist(new_linear,new_angular)
        if binding2 is not None:
             new_linear = self.linear + binding2[0]
             new_angular = self.angular + binding2[1]
             self.write_twist(new_linear,new_angular)

    def _is_special_key(self, key):
        try:
            key.char
            return False
        except AttributeError:
            return True
        
    def write_twist(self, linear=None, angular=None):
        if linear is not None:
            if linear <= self.LINEAR_MAX or linear >= -self.LINEAR_MAX:
                self.linear = linear
            else:
                self.get_logger().error(
                    f"Trying to set a linear speed {linear} outside of allowed range of [{-self.LINEAR_MAX}, {self.LINEAR_MAX}]"
                )
        if angular is not None:
            if angular <= self.ANGULAR_MAX or angular >= -self.ANGULAR_MAX:
                self.angular = angular
            else:
                self.get_logger().error(
                    f"Trying to set a angular speed {angular} outside of allowed range of [{-self.ANGULAR_MAX}, {self.ANGULAR_MAX}]"
                )
        self._update_screen()

    def _make_twist_unstamped(self, linear, angular):
        twist = EscAndSteering()
        twist.esc_percent = float(linear)
        twist.steering_percent = float(angular)
        return twist

    def _publish(self):
        twist = self._make_twist(self.linear, self.angular)
        self.publisher_.publish(twist)

    def _update_screen(self):
        sys.stdout.write(f"Linear: {self.linear:.2f}, Angular: {self.angular:.2f}\r")
def main():
    try:
        rclpy.init()
        node = KeyboardTeleop()
        rclpy.spin(node)
        rclpy.shutdown()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    main()
