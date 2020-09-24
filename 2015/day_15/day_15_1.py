# import re

ingredients = []
# index 1 - 5 = ingredient attr
attr_total = [0, 0, 0, 0]

maximum = 0

def calc(index, tsp):
	global maximum

	for i in xrange(0, 101 - tsp):
		for x in xrange(0, 4):
			attr_total[x] += ingredients[index][x] * i
		if index + 1 < len(ingredients) - 1:
			calc(index + 1, tsp + 1)
		else:
			total = 1
			for x in xrange(0, 4):
				attr_total[x] += ingredients[index + 1][x] * (100 - i)
				total *= attr_total[x] if attr_total[x] > 0 else 0
				attr_total[x] = 0
			# if i == 44:
			# 	print(str(maximum))
			maximum = max(total, maximum)
#Works for test input but not puzzle input someh0ow

with open('input') as input:
	lst = [int(re.split(', | |\n', line)[x]) for line in input for x in [2,4,6,8]]
	ingredients = [lst[x:x + 4] for x in [0, 4]]
	calc(0, 0)
	print(str(maximum))
