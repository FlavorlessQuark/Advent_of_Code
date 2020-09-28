import itertools

config = [5000,3018894606110]

with open('input') as input:
	pkg = [int(line[:-1]) for line in input]

weight = sum(pkg) / 4

for i in range (2, len(pkg) - 1):
	for comb in itertools.combinations(pkg, i):
		if sum(comb) != weight:
			continue
		if config[0] >= i:
			config[0] = i
			config[1] = min(config[1], reduce(lambda x, y: x*y, comb))
			# print(comb)
		else:
			break

print(config)
