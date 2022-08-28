# import sys
# sys.path.append("..")

# from ..aoc import aoc

# day = aoc()

# day.get_nums()

# print(day)
import re
with open('input') as input:
	inp = [line.rstrip() for line in input]

total = sum([int(x) for x in inp])

print(total)
