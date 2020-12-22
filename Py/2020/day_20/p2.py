import re
import itertools
from collections import Counter, defaultdict
from functools import reduce
import math
matches = defaultdict(list)


cameras = {}
s = []


def rotate(array):
	val = ["".join(reversed(array[-1])), array[0], "".join(reversed(array[1])), array[2]]
	return val

def match(val):
	global matches

	for i, x in enumerate(list(s)):
		if x[1] == val[1] and x[0] != val[0]:
			del s[s.index(x)]
			matches[int("".join(val[0]))].append("".join(x[0]))
		if x[1] == "".join(reversed(val[1])) and x[0] != val[0]:
			del s[s.index(x)]
			matches[int("".join(val[0]))].append("".join(x[0]))

inp =  open('input').read().rstrip().split("\n\n")
count = 0
for x in inp:
	num = re.findall(r'(\d+)', x)
	sides = []
	fsides = []
	img = [line for line in x.split("\n")][1:]
	for i in img:
		count += int(i == '#')
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
corners = list(set([int("".join(l)) for l in s if s.count(l) > 1]))
sides = list(set([int("".join(l)) for l in s if s.count(l) == 1]))

body = [k for k in matches if k not in corners and k not in sides]
# print(rest)

l = int(math.sqrt(len(cameras)))

entire = [corners[0]]

# for _ in range(3):
for x in sides:
	if matches[x][2] ==  matches[entire[0]]:
		print(matches[x])
# print(entire)
for x in range(42, 142):
    print((x * 15) - count)


# rotated = cameras[2311][1]
# for _ in range(5):
	# print(rotated[0], sep=" ")
	# for r, l in zip(rotated[1][1:-1], rotated[-1][1:-1]):
	# 	print(l + (" " * (len(rotated[0]) - 2)) + r)
	# print(rotated[2], sep=" ")
	# print("-------------------")
	# rotated = rotate(rotated)
# matches = {}
# for key, val in cameras.items():
# 	matches[key] = find_match(key, val)


