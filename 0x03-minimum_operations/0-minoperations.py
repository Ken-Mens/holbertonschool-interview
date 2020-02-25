#!/usr/bin/python3
import math
""""
Your text editor can execute only two operations in this file:
Copy All and Paste.Given a number n, write a method that calculates
the fewest number of operations.
"""


def sum_primes(n):
    result = 0

    if n <= 1:
        return result
    for idx in range(2, int(math.sqrt(n) + 1)):
        while n % idx == 0:
            n = n // idx
            result = result + idx
    if n >= 2:
        result = result + n
    return result

    def minOperations(n):
        if type(n) != int:
            return 0
    return sum_primes(n)
    