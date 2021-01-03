from collections  import defaultdict
import re

with open('input') as input:
	inp = [line.rstrip() for line in input]

d = defaultdict(int)

for x in inp:
	ids , rest = x.split('@ ')

	x0, y0, w, h  = list(map(int,re.findall(r'(\d+)', rest)))
	for y in range(1, h + 1):
		for x in range(1, w + 1):
			d[(y0 + y, x0 + x)] += 1
			
print(sum([1 for x in d.values() if x >= 2]))
