import itertools

config = [50,80000]

with open('input') as input:
	pkg = [int(line[:-1]) for line in input]

weight = sum(pkg) / 3

for i in range len(pkg):
	for comb in itertools.combinations():
		

print(weight)
