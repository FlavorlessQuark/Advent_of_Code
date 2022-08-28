import itertools
from functools import reduce

config = [5000,3018894606110]

with open('input') as input:
	pkg = [int(line[:-1]) for line in input]

weight = sum(pkg) // 4

for i in range(1, len(pkg)):
	for comb in itertools.combinations(pkg, i):
		if sum(comb) == weight:
			print(config[0], i)
			if config[0] >= i:
				config[0] = i
				config[1] = min(config[1], reduce(lambda x, y: x*y, comb))
			else :
				print("Solution :", config[1])
				exit()


