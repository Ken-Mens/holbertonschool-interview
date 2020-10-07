#!/usr/bin/python3
""" return list of integers that represent Pascale's triangle"""

def pascal_triangle(n):
    a = [[] for idx in range(n)]
    for idx in range(0, n):
        for j in range(idx + 1):
            if (j < idx):
                if (j == 0):
                    a[idx].append(1)
                else:
                    a[idx].append(a[idx - 1][j] + a [idx -1][j -1])
            elif (j == idx): 
                a[idx].append(1)
    return a