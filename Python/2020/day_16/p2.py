import re
import itertools
from functools import reduce

with open('input') as input:
	inp = [line.rstrip() for line in input]

ranges = []
fields = []
for i, x in enumerate(inp):
	if ("ticket" not in x):
		r = re.findall(r'\d+', x)
		if len(r) > 0:
			fields.append([inp[i][:inp[i].index(":")], [x for x in range(int(r[0]), int(r[1]) + 1)] + [x for x in range(int(r[2]), int(r[3]) + 1)]])
			ranges += [x for x in range(int(r[0]), int(r[1]) + 1)]
			ranges += [x for x in range(int(r[2]), int(r[3]) + 1)]
	else:
		break

mine = inp[i + 1]
total = []
delete = []
for n in range(i + 4, len(inp)):
	for num in re.findall(r'\d+', inp[n]):
		if int(num) not in ranges:
			delete.append(n)

correct = []
ordered = []
for i, line in enumerate(inp):
	if i not in delete and ":" not in line and len(line) > 0:
		correct.append(inp[i].split(','))

correct = correct[1:]

p = [x for x in itertools.permutations(fields,len(fields))]

ordered = []

for x in p:
	keep = True
	for i, val in enumerate(x):
		if not all([int(correct[n][i]) in val[1] for n in range(len(correct))]):
			keep = False
	if keep == True:
		for i, val in enumerate(x):
			if ("departure" in val[0]):
				total += [int(correct[i][n])for n in range(len(correct))]
print(total)

print(reduce(lambda x , y : x * y,total))

