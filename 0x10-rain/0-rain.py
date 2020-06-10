#!/usr/bin/python3
"""0_rain"""


def rain(walls):
    """raindop function calculating how much water will be retained"""
    if type(walls) is not list:
        return 0
    if len(walls) is 0:
        return 0
    water = 0
    for idx in range(1, len(walls)-1):
        mid = walls[idx]
        left = max(walls[:idx])
        right = max(walls[idx + 1:len(walls)])
        if mid < left and mid < right:
                water += min([left, right]) - mid
    return water
