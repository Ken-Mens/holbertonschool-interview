#!/usr/bin/python3
"""Algo checking wheter or not lockboxes can be opened"""

def canUnlockAll(boxes):
    """ Creates a set for non duplicates and list for
    found keys"""

    k_opened = set()
    k_found = [0]

    while len(k_opened) < len(boxes):
        if len(boxes) == 0:
            return True
        if not k_found or not isinstance(boxes, list):
            return False
        key = k_found.pop()
        if key not in k_opened:
            k_opened.add(key)
            k_found.extend(boxes[key])
    return True