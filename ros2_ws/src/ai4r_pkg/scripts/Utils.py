#!/usr/bin/env python3

import numpy as np
import cv2
import yaml

class Util:
    def __init__(self) -> None:
        pass

    def get_resolution(self,resolution):
        resolutions = {
            "480p": (640, 480),
            "540p": (960, 540),
            "720p": (1280, 720),
            "1080p": (1920, 1080)
        }
        return resolutions[resolution]

    def set_capture_properties(self,capture, resolution, frame_rate, exposure = None):
        """Set video capture properties"""
        width, height = self.get_resolution(resolution)
        capture.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        capture.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        capture.set(cv2.CAP_PROP_FPS, frame_rate)
        if exposure is not None:
            capture.set(cv2.CAP_PROP_EXPOSURE, exposure)


        # Thresholding operations

    def thresh_image(self,img, range):
        """
        img: grayscale image
        range: tuple of (min, max) threshold values
        """
        return cv2.inRange(img, range[0], range[1])

    def combine_images(self,images):
        """
        images: list of images to combine
        """
        if len(images) == 1:
            return images[0]
        else:
            return cv2.bitwise_and(*images)

    # Morphological Operations

    def erode(self,image, kernel_size=5, iterations=1):
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
        erosion = cv2.erode(image, kernel, iterations=iterations)
        return erosion

    def dilate(self,image, kernel_size=5, iterations=1):
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
        dilation = cv2.dilate(image, kernel, iterations=iterations)
        return dilation

    def open_op(self,image, kernel_size=5, iterations=1):
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
        opening = cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel, iterations=iterations)
        return opening

    def close_op(self,image, kernel_size=5, iterations=1):
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (kernel_size, kernel_size))
        closing = cv2.morphologyEx(image, cv2.MORPH_CLOSE, kernel, iterations=iterations)
        return closing

    # Other Operations

    def get_largest_contour(self,img):
        """
        Get the largest contour from the image
        """
        contours, _ = cv2.findContours(img, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        contours = sorted(contours, key=cv2.contourArea, reverse=True)

        img = np.zeros_like(img)
        cv2.drawContours(img, [contours[0]], -1, 255, -1)
        return img

    def gauss_blur(img, kernel_size=3):
        """
        Apply a Gaussian Blur to the image
        """
        return cv2.GaussianBlur(img, (kernel_size, kernel_size), 0)

    # # Thinning

    # def thin_op(img):
    #     """
    #     Apply Thinning to the image
    #     """
    #     return cv2.ximgproc.thinning(img)

    # Manual Search
    # TODO: Optimization
    def manual_search(self,image, step = 50):
        # Get points on the image
        points = np.argwhere(image > 0)
        # Sort the points by x
        points = points[points[:,0].argsort()]
        y = points[-1][0]
        x_values = []
        y_values = []
        x_step = None
        while y > 0:
            x = points[points[:,0] == y][:,1]
            x = x[len(x)//2]    # median
            x_values.append(x)
            y_values.append(y)
            y -= step
            # Calculate angle between most recent points
            if len(y_values) > 2:
                angle = np.arctan2(x_values[-1] - x_values[-2], y_values[-1] - y_values[-2])
                angle = np.degrees(angle)
                if angle > 0 and angle < 135:   # The line is moving right
                    x_step = step
                    break
                elif angle < 0 and angle > -135:    # The line is moving left
                    x_step = -step
                    break
        
        if x_step:
            while x > 0 and x < image.shape[1]:
                try:
                    y = points[points[:,1] == x][:,0]
                    y = y[len(y)//2]    # median
                    x_values.append(x)
                    y_values.append(y)
                    x += x_step
                except:
                    break
        
        points = list(zip(x_values, y_values))
        return points

    def plot_points(self,image, points):
        # convert img to color
        img = cv2.cvtColor(image, cv2.COLOR_GRAY2RGB)
        # create an image with the same shape as img
        #img = np.zeros_like(img)
        for point in points:
            cv2.circle(img, point, 5, (255, 0, 0), -1)
        return img

        # Save config to a file
    def save_config(config, file_path):
        with open(file_path, 'w') as f:
            yaml.dump(config, f)

    # Load the config from a file
    def load_config(file_path):
        with open(file_path, 'r') as f:
            config = yaml.load(f, Loader=yaml.FullLoader)
        return convert_bool_strings(config)

    # Convert boolean strings back to boolean values
    def convert_bool_strings(obj):
        if isinstance(obj, dict):
            return {k: convert_bool_strings(v) for k, v in obj.items()}
        elif isinstance(obj, list):
            return [convert_bool_strings(item) for item in obj]
        elif isinstance(obj, str):
            if obj.lower() == 'true':
                return True
            elif obj.lower() == 'false':
                return False
            else:
                return obj
        else:
            return obj