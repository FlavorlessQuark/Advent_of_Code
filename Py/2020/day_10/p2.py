import collections

inp = []

def find_good():
	totals = collections.Counter()
	totals[0] = 1
	for x in inp:
		totals[x] = sum([totals[x - i] for i in range(1, 4)])
	return totals

with open('input') as input:
	inp = [int(line.rstrip()) for line in input]

inp.sort()
totals = find_good()
print("Solution", totals[inp[-1]])
