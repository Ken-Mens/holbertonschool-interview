#!/usr/bin/python3
"""
Rotate a 2d matrix 90 degrees
"""


def rotate_2d_matrix(matrix):
    """
    rotate matrix in place by 90 degrees
    """
    n = len(matrix)
    for y in range(0, int(n/2)):
        for idx in range(y, n-y-1):
            foo = matrix[y][idx]
            matrix[y][idx] = matrix[n-idx-1][y]
            matrix[n-idx-1][y] = matrix[n-y-1][n-idx-1]
            matrix[n-y-1][n-idx-1] = matrix[idx][n-y-1]
            matrix[idx][n-y-1] = foo
