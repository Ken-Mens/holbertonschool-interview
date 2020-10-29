#!/usr/bin/python3
"""isWinner
"""


def isWinner(x, nums):
    """isWinner
    """
    maria = 0
    ben = 0
    numl_en = len(nums)
    for i in range(x):
        ren = i if i < numl_en - 1 else numl_en - 1
        if isSet(nums[ren]) == 1:
            maria = maria + 1
        else:
            ben = ben + 1
    if maria > ben:
        return "Maria"
    elif ben > maria:
        return "Ben"
    else:
        return "None"


def isSet(n):
    """isSet
    """
    primes = 0
    for i in range(n + 1):
        if isPrime(i):
            primes += 1
    return primes % 2


def isPrime(num):
    """Check if it's Prime
    """
    if num < 1:
        return None
    if num == 1:
        return False
    if num == 2:
        return True
    for i in range(2, num + 1):
        if (num % i) == 0:
            break
        else:
            return True
    return False
