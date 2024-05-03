#!/usr/bin/env python3

import numpy as np
import cv2

class LineDetectorCircle:
    def __init__(
        self, radius = 50, start_angle=-60, end_angle=60, draw = False):
        self.start_angle = start_angle + 270
        self.end_angle = end_angle + 270
        self.draw = draw

        self.hash_table = self.create_circle_hash_table(radius)

    @staticmethod
    def create_circle_hash_table(radius):
        hash_table = {
            'x': np.zeros(361, dtype=np.int8),
            'y': np.zeros(361, dtype=np.int8)
        }
        for angle in range(361):
            hash_table['x'][angle] = int(radius * np.cos(np.deg2rad(angle)))
            hash_table['y'][angle] = int(radius * np.sin(np.deg2rad(angle)))
        return hash_table

    def __call__(self, img):
        self.img = img
        self.img_shape_0 = img.shape[0]
        self.img_shape_1 = img.shape[1]
        if self.draw:
            self.img_color = cv2.cvtColor(self.img, cv2.COLOR_GRAY2BGR)
        
        start = self.get_starting_point()
        if start is None: return None

        #print('Starting point: ', start)

        points = [start, ]
        next_point = self.get_next_point(start)
        if next_point is not None:
            points.append(next_point)
            #print('Next point: ', next_point)

        if self.draw:
            cv2.circle(self.img_color, start, 3, (0, 0, 255), -1)
            if next_point is not None:
                cv2.circle(self.img_color, next_point, 3, (0, 0, 255), 1)

        while next_point is not None:
            theta = np.arctan2(points[-1][1] - points[-2][1], points[-1][0] - points[-2][0])
            delta = int(90 + np.rad2deg(theta))
            next_point = self.get_next_point(next_point, delta)
            if next_point is not None:
                points.append(next_point)
                #print('Next point: ', next_point)
        
        return points

    def get_next_point(self, current_point, delta = 0):
        points = self.get_points_on_circle(current_point, delta)

        # Check if any point is out of bounds
        valid_points_mask = np.logical_and.reduce((
            points[:, 0] >= 0,
            points[:, 0] < self.img_shape_1,
            points[:, 1] >= 0,
            points[:, 1] < self.img_shape_0
        ))

        # Return None if any of the points is invalid
        # if not np.all(valid_points_mask): return None       

        # TODO: Instead of stopping, we can just filter out valid points, 
        # and only stop if there are no more valid points to search for

        # Return None if more than half of the points are invalid
        if np.sum(valid_points_mask) < len(valid_points_mask) / 2:
            return None

        points = points[valid_points_mask]

        if self.draw:
            for point in points:
                cv2.circle(self.img_color, tuple(point), 3, (0, 255, 0), -1)
        
        # THERE WAS A BUG HERE WHICH HAS BEEN FIXED
        valid_mask = self.img[points[:, 1], points[:, 0]] > 0
        points_on_lane = points[valid_mask]

        # Return none if no point is found
        if len(points_on_lane) == 0: return None       

        next_point = points_on_lane[int(len(points_on_lane)/2)]

        if self.draw:
            for point in points_on_lane:
                cv2.circle(self.img_color, tuple(point), 3, (255, 0, 0), -1)
                # draw the next point
                cv2.circle(self.img_color, tuple(next_point), 3, (0, 0, 255), -1)

        # Return the median point (next point)
        return tuple(next_point)

    def get_points_on_circle(self, center, delta = 0):
        """
        Get points on a circle using the hash table
        """
        angles = np.arange(self.start_angle + delta, self.end_angle + delta) % 360
        x_offsets = self.hash_table['x'][angles]
        y_offsets = self.hash_table['y'][angles]
        points = np.column_stack((x_offsets + center[0], y_offsets + center[1]))
        return points
    
    def get_starting_point(self):
        last_idx = -1
        while abs(last_idx) < self.img_shape_0//2:
            last_row = self.img[last_idx, :]
            lane_exists = np.where(last_row > 0)[0] # lane exists where there is a nonzero value
            if len(lane_exists) > 0: # If lane exists
                lane_center = np.median(lane_exists)
                center_point = (int(lane_center), (self.img_shape_0 + last_idx))
                return center_point
            # Else move up by 1 pixel
            last_idx -= 1       # Removed BUG here
        return None
