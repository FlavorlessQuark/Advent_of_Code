from collections  import defaultdict, Counter
import re

with open('input') as input:
	inp = [line.rstrip() for line in input]

d = defaultdict(list)
i = {}


for x in inp:
	ids , rest = x.split('@ ')

	x0, y0, w, h  = list(map(int,re.findall(r'(\d+)', rest)))
	i[ids] = w * h
	for y in range(1, h + 1):
		for x in range(1, w + 1):
			d[(y0 + y, x0 + x)].append(ids)

c = defaultdict(int)
for x in d.values():
	if len(x) == 1:
		c[x[0]] += 1

for x in c:
	if i[x] == c[x]:
		print(x)
		exit(0)
