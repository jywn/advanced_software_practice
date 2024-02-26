import numpy as np
import matplotlib.pyplot as plt
from scipy.signal import find_peaks
from scipy.interpolate import splprep, splev
from scipy.optimize import minimize
import time


class LateralController:
    '''
    Lateral control using the Stanley controller

    functions:
        stanley 

    init:
        gain_constant (default=5)
        damping_constant (default=0.5)
    '''


    def __init__(self, gain_constant=3, damping_constant=0.6):

        self.gain_constant = gain_constant
        self.damping_constant = damping_constant
        self.previous_steering_angle = 0


    def stanley(self, waypoints, speed):
        '''
        ##### TODO #####
        one step of the stanley controller with damping
        args:
            waypoints (np.array) [2, num_waypoints]
            speed (float)
        '''
        
        # derive orientation error as the angle of the first path segment to the car orientation
        dx = waypoints[0, 1] - waypoints[0, 0]
        dy = waypoints[1, 1] - waypoints[1, 0]
        heading_error = np.arctan(dx/dy)
        # derive stanley control law
        # derive cross track error as distance between desired waypoint at spline parameter equal zero ot the car position
        crosstrack_error = waypoints[0, 0] - 48
        # prevent division by zero by adding as small epsilon
        epsilon = 1E-10
        # derive damping
        # clip to the maximum stering angle (0.4) and rescale the steering action space
        # heading_error + arctan(ke/(v+e))
        stanley = heading_error + np.arctan((self.gain_constant * crosstrack_error) / (epsilon + speed))
        steering = stanley
        steering = np.clip(steering, -0.7, 0.7)
        ans = steering - self.damping_constant * (steering - self.previous_steering_angle)
        ans = np.clip(ans, -0.7, 0.7)
        self.previous_steering_angle = ans
        return ans
