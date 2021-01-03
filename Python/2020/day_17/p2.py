import itertools
from collections import defaultdict
from copy import deepcopy


with open('input') as input:
	d = {(x, y, 0, 0):c for y, line in enumerate(input) for x, c in enumerate(line.rstrip()) }

d = defaultdict(lambda : '.', d)

dirs = [x for x in itertools.product(range(-1,2), repeat=4)]

del dirs[dirs.index((0,0,0, 0))]

for _ in range(6):
	for key in list(d.keys()):
		for val in dirs:
			d[(key[0] + val[0], key[1] + val[1], key[2] + val[2], key[3] + val[3])]
	d2 = d.copy()
	for key in list(d.keys()):
		t = sum([1 for val in dirs if d[(key[0] + val[0], key[1] + val[1], key[2] + val[2], key[3] + val[3])] == '#'])
		if (d[key] == '.' and t == 3):
			d2[key] = '#'
		if (d[key] == '#' and not (2 == t or t == 3)):
			d2[key] = '.'
	d = d2

print("Solution :",sum([1 for val in d if d[val] == '#']))
