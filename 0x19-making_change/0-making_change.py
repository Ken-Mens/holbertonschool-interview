#!/usr/bin/python3
"""
Given a pile of coins of different values, determine the fewest number of coins
needed to match a certain amount.
"""


def makeChange(coins, total):
    """
    change making function
    """
    if (total == 0):
        return 0
    coins.sort(reverse=True)
    change = 0
    for c in coins:
        if c <= 0:
            pass
        foo = (total // c)
        change += foo
        total -= (foo * c)
    if total != 0:
        return (-1)
    return change
