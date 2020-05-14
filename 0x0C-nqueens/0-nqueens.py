#!/usr/bin/python3
"""nqueens chessboard problem"""
import sys


def launch(pieces):
    solutions = []
    for row in range(0, pieces):
        for solution in solutions:
            print(pieces[row][solutions], end = " ") 
        print(solution)
