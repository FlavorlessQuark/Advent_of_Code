import re
from functools import reduce

total = 0
cube = lambda x : x[0] * x[1] * x[2]
ribbon = lambda x : x[0] * 2 + x[1] * 2

def parse_line(dimensions_str):
	global total
	dimensions = [int(number) for number in re.findall(r'\d*', dimensions_str) if len(number) > 0]

	total += ribbon(sorted(dimensions))
	total += reduce(lambda x, y: x * y, dimensions)

with open('input') as input:
	for line in input:
		parse_line(line)

print("Solution: ", str(total))
