import itertools

with open('input') as input:
	inp = [int(line.rstrip()) for line in input]

highest = max(inp) + 3

chain = [0]
l = len(inp)
i = 0


for x in range(l):
	good = [y for y in inp if y == chain[i]  + 1 or y == chain[i] + 2 or y == chain[i] + 3]
	chain.append(min(good))
	i += 1
chain.append(highest)
print("Solution", len(ones) * (len(threes) + 1))
