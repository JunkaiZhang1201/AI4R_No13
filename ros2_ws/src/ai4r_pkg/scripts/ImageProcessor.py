#!/usr/bin/env python3
import yaml
import os  
import cv2 
import numpy as np

import rclpy
from rclpy.node import Node
from rclpy.qos import qos_profile_system_default
from LineDetectorCircle import LineDetectorCircle
from LineDetectorEllipse import LineDetectorEllipse
from Utils import Util
from ai4r_interfaces.msg import IntArray,ElementInt
from std_msgs.msg import Bool as Bool1
from rclpy.parameter import Parameter

USB_PORT = 4

# Import any python modules or libraries here
#from ai4r_pkg.module_to_import import function


# Create a class which inherits from the rclpy Node class. Each ROS2 Python node that you’ll write will be a superset of “rclpy.node.Node”.
class ImageProcessor(Node):
    # Create publishers, subscribers, and other ROS2 functionalities in the constructor
    def __init__(self):
        super().__init__('image_processor_node')    # Initialize the Node object, and we pass the node name to it.
        self.declare_parameters(
            namespace='',
            parameters=[
                ("hls_select", rclpy.Parameter.Type.STRING_ARRAY),
                ("h_range", rclpy.Parameter.Type.INTEGER_ARRAY),
                ("l_range", rclpy.Parameter.Type.INTEGER_ARRAY),
                ("s_range", rclpy.Parameter.Type.INTEGER_ARRAY),
                ("morph", rclpy.Parameter.Type.BOOL),
                ("erosion", rclpy.Parameter.Type.BOOL),
                ("dilation", rclpy.Parameter.Type.BOOL),
                ("opening", rclpy.Parameter.Type.BOOL),
                ("closing", rclpy.Parameter.Type.BOOL),
                ("kernel_erode", rclpy.Parameter.Type.INTEGER_ARRAY),
                ("kernel_dilate",rclpy.Parameter.Type.INTEGER_ARRAY),
                ("kernel_open",rclpy.Parameter.Type.INTEGER_ARRAY),
                ("kernel_close",rclpy.Parameter.Type.INTEGER_ARRAY),
                ("largcon",rclpy.Parameter.Type.BOOL),
                ("blur",rclpy.Parameter.Type.BOOL),
                ("kernel_blur",rclpy.Parameter.Type.INTEGER_ARRAY),
                ("shape",rclpy.Parameter.Type.STRING),
                ("radius",rclpy.Parameter.Type.INTEGER),
                ("start_angle",rclpy.Parameter.Type.INTEGER),
                ("end_angle",rclpy.Parameter.Type.INTEGER),
                ("a",rclpy.Parameter.Type.INTEGER),
                ("b",rclpy.Parameter.Type.INTEGER),
                ("draw",rclpy.Parameter.Type.BOOL)
            ])
        self.hls_select = self.get_parameter_or("hls_select",Parameter("default_hls",Parameter.Type.STRING_ARRAY,[]))
        self.h_range = self.get_parameter_or("h_range",Parameter("default_h_range",Parameter.Type.INTEGER_ARRAY,[]))
        self.l_range = self.get_parameter_or("l_range",Parameter("default_l_range",Parameter.Type.INTEGER_ARRAY,[]))
        self.s_range = self.get_parameter_or("s_range",Parameter("default_s_range",Parameter.Type.INTEGER_ARRAY,[]))
        self.morph = self.get_parameter_or("morph",Parameter("default_morph",Parameter.Type.BOOL,False))
        self.erosion = self.get_parameter_or("erosion",Parameter("default_erosion",Parameter.Type.BOOL,False))
        self.dilation = self.get_parameter_or("dilation",Parameter("default_dilation",Parameter.Type.BOOL,False))
        self.opening = self.get_parameter_or("opening",Parameter("default_opening",Parameter.Type.BOOL,False))
        self.closing = self.get_parameter_or("closing",Parameter("default_closing",Parameter.Type.BOOL,False))
        self.kernel_erode = self.get_parameter_or("kernel_erode",Parameter("default_kernerode",Parameter.Type.INTEGER_ARRAY,[]))
        self.kernel_dilate = self.get_parameter_or("kernel_dilate",Parameter("default_kerndila",Parameter.Type.INTEGER_ARRAY,[]))
        self.kernel_open = self.get_parameter_or("kernel_open",Parameter("default_kernopen",Parameter.Type.INTEGER_ARRAY,[]))
        self.kernel_close = self.get_parameter_or("kernel_close",Parameter("default_kernclose",Parameter.Type.INTEGER_ARRAY,[]))
        self.largcon = self.get_parameter_or("largcon",Parameter("default_largcon",Parameter.Type.BOOL,False))
        self.blur = self.get_parameter_or("blur",Parameter("default_blur",Parameter.Type.BOOL,False))
        self.kernel_blur = self.get_parameter_or("kernel_blur",Parameter("default_kernblur",Parameter.Type.INTEGER_ARRAY,[]))
        self.shape = self.get_parameter_or("shape",Parameter("default_shape",Parameter.Type.STRING,""))
        self.radius = self.get_parameter_or("radius",Parameter("default_radius",Parameter.Type.INTEGER,0))
        self.start_angle = self.get_parameter_or("start_angle",Parameter("default_startangle",Parameter.Type.INTEGER,0))
        self.end_angle = self.get_parameter_or("end_angle",Parameter("default_endangle",Parameter.Type.INTEGER,0))
        self.a = self.get_parameter_or("a",Parameter("default_a",Parameter.Type.INTEGER,0))
        self.b = self.get_parameter_or("b",Parameter("default_b",Parameter.Type.INTEGER,0))
        self.draw = self.get_parameter_or("draw",Parameter("default_draw",Parameter.Type.BOOL,False))


        self.error_flag = Bool1()
        self.error_flag = False
        self.Util1 = Util()
        
        self.cap = cv2.VideoCapture(USB_PORT)
        self.res = '480p'
        self.frame_rate = 30
        self.exposure = None
        
        self.update_count = 0
        self.Util1.set_capture_properties(self.cap,self.res,self.frame_rate,self.exposure)

        #self.get_logger().info("str%s",cv2.get)
        self.error_pub = self.create_publisher(
            Bool1, "CV_Timeout_Flag", qos_profile_system_default
        )

        self.img_point_pub = self.create_publisher(
            IntArray,"Image_Point",qos_profile_system_default
        )
        timer_period = (1/self.frame_rate)
        self.timer = self.create_timer(timer_period,self.camera_callback)

    def camera_callback(self):
        self.ret,self.frame = self.cap.read()
        points, self.img_det = self.process(self.frame)
        self.ImgPoint = IntArray()
        self.get_logger().info("%s" %points)

        if (self.update_count > ((1/2)*self.frame_rate)):
            self.error_flag = True
            trial1 = Bool1()
            trial1.data = self.error_flag
            self.error_pub.publish(trial1)

        if points is None:
            self.get_logger().info("No Line Found")
            self.update_count += 1
            return
        if points is not None:
            if (len(points) < 5):
                self.update_count += 1
            else:
                self.error_flag = False
                trial1 = Bool1()
                trial1.data = self.error_flag
                self.error_pub.publish(trial1)
                self.update_count = 0

            for i in range(len(points)):
                new_subpoint = ElementInt()
                new_subpoint.elements.append(points[i][0])
                new_subpoint.elements.append(points[i][1])
                self.ImgPoint.lists.append(new_subpoint)
            
            self.img_point_pub.publish(self.ImgPoint)

    def load_image(self, image):
        """Converts the image to HLS and returns the HLS channels"""
        hls = cv2.cvtColor(self.frame, cv2.COLOR_BGR2HLS)
        self.h, self.l, self.s = cv2.split(hls)
    
    def threshold_image(self):
        thresholded = []
        if not len(self.hls_select.value) == 0:
            for channel in self.hls_select.value:
                if channel == "Hue":
                    thresholded.append(self.Util1.thresh_image(self.h, self.h_range.value))
                elif channel == "Lightness":
                    thresholded.append(self.Util1.thresh_image(self.l, self.l_range.value))
                elif channel == "Saturation":
                    thresholded.append(self.Util1.thresh_image(self.s, self.s_range.value))

        self.im = self.Util1.combine_images(thresholded)
        return self.im

    def preprocess_image(self):
        """Applies pre-processing operations on the image such as - 
        - Morphological operations (optional)
        - Get Largest contour (optional)
        - Blur (optional)
        """
        # Morphological operations
        if self.morph.value:
            if self.erosion.value:
                self.im = self.Util1.erode(self.im, tuple(self.kernel_erode.value))
            if self.dilation.value:
                self.im = self.Util1.dilate(self.im, tuple(self.kernel_dilate.value))
            if self.opening.value:
                self.im = self.Util1.open_op(self.im, tuple(self.kernel_open.value))
            if self.closing.value:
                self.im = self.Util1.close_op(self.im, tuple(self.kernel_close.value))
        
        # Get largest contour
        if self.largcon.value:
            self.im = self.Util1.get_largest_contour(self.im)

        # Blur operation        
        if self.blur.value:
            self.im = self.Util1.gauss_blur(self.im, tuple(self.kernel_blur.value))

        return self.im

    def detect_line(self):
        """Detects the line using either of the specified methods"""
        if self.shape.value == "Circle":
            ld = LineDetectorCircle(self.radius.value, self.start_angle.value, self.end_angle.value, draw = self.draw.value)
        elif self.shape.value == "Ellipse":
            ld = LineDetectorEllipse(self.a.value, self.b.value, self.start_angle.value, self.end_angle.value, draw = self.draw.value)
        points = ld(self.im)
        img_det = ld.img_color if self.draw.value else None
        return points, img_det
    
    def process(self, image):
        """Processes the image and returns the detected line"""
        self.load_image(self.frame)
        self.threshold_image()
        self.preprocess_image()
        points, img_det = self.detect_line()
        return points, img_det
    
    # The timer_callback() method is part of the MyNode class.
    def timer_callback(self):
        self.get_logger().info("Hello ROS2")    # Use another inherited Node method: get_logger().info(). This will print a ROS2 log on the terminal.




def main(args=None):
    rclpy.init(args=args)
    node = ImageProcessor() # Instantiate the custom node we’ve written
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()