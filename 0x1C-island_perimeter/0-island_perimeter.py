#!/usr/bin/python3


def island_perimeter(grid):
    if not grid:
        return (0)
    sum = 0
    for idx in range(len(grid)):
        for xdi in range(len(grid[0])):
            if grid[idx][xdi] == 1:
                sum += 4
                if idx != 0 and grid[idx-1][xdi] == 1:
                    sum -= 2
                if xdi != 0 and grid[idx][xdi-1] == 1:
                    sum -= 2
    return sum
        