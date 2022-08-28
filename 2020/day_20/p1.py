import re
from functools import reduce

inp =  open('input').read().rstrip().split("\n\n")

cameras = {}
s = []

def match(val):
	found = False
	for x in list(s):
		if (x[1] == val[1] or x[1] == "".join(reversed(val[1]))) and x[0] != val[0]:
			del s[s.index(x)]
for x in inp:
	num = re.findall(r'(\d+)', x)
	sides = []
	img = [line for line in x.split("\n")][1:]
	sides.append(img[0])
	sides.append("".join([c[-1] for c in img]))
	sides.append(img[-1])
	sides.append("".join([c[0] for c in img]))
	for x in sides:
		s.append((num, x))
	cameras[int(num[0])] = (sides, fsides)

for y in list(s):
	match(y)

s = [l[0] for l in s]
k = set(["".join(l) for l in s if s.count(l) > 1])
print(reduce(lambda x, y: int(x) * int(y), k))

