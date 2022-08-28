import re
from collections import defaultdict

with open('input') as input:
	inp = [line.rstrip() for line in input]

d = defaultdict(int)

dr = {"e" :0,"n": 0, "w": 0}

ref = {"e": [("e", 2)], "ne":[("n", 1), ("e", 1)],"nw":[("n", 1), ("e", -1)], "w":[("e", -2)], "se":[("n", -1), ("e", 1)], "sw":[("n", -1), ("e", -1)]}
for line in inp:
	dr = {"e":0,"n":0}
	for x in re.findall(r'(se)|(sw)|(ne)|(nw)|(w)|(e)', line):
		s = "".join(x)
		for y in ref[s]:
			dr[y[0]] += y[1]
	# print(dr.values())
	d[(dr["e"], dr["n"])] += 1

c = 0

for k, v in d.items():
	if v % 2 != 0:
		c += 1
print(c)
