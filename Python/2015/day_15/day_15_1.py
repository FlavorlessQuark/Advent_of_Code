import itertools
from functools import reduce
import re

with open('input') as input:
	lst = [line for line in input]
ingredients = [list(map(int, re.findall(r'-?\d+', x))) for x in lst]
arr = [x for x in itertools.product(range(0, 101), repeat=len(ingredients)) if sum(x) == 100]

maximum = 0
for possible in arr:
	attr_total = [0, 0, 0, 0, 0]
	for item in range(len(ingredients)):
		attr_total[0] += (ingredients[item][0] * possible[item])
		attr_total[1] += (ingredients[item][1] * possible[item])
		attr_total[2] += (ingredients[item][2] * possible[item])
		attr_total[3] += (ingredients[item][3] * possible[item])
		attr_total[4] += (ingredients[item][4] * possible[item])
	for i in range(len(attr_total)):
		if attr_total[i] < 0:
			attr_total[i] = 0
	maximum = max(reduce(lambda x, y: x * y, attr_total), maximum)

print("Solution : ", maximum)
