#!/usr/bin/python3
""" return list of integers that represent Pascale's triangle"""

def pascal_triangle(n):
    a = [[] for idx in range(0, n)]
    for idx in range(0, n):
        for foo in range(idx + 1):
            if (foo < idx):
                if (foo == 0):
                    a[idx].append(1)
                else:
                    a[idx].append(a[idx - 1][foo] + a [idx - 1][foo - 1])
            elif (foo == idx): 
                a[idx].append(1)
    return a