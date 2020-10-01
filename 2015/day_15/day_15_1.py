import re

ingredients = []
attr_total = [0, 0, 0, 0]

maximum = 0

def calc(index, tsp):
	global maximum


with open('input') as input:
	lst = [int(re.split(', | |\n', line)[x]) for line in input for x in [2,4,6,8,10]]
	ingredients = [lst[x:x + 4] for x in [0,2, 4,]]
	# calc(0, 0)
	print(ingredients)
