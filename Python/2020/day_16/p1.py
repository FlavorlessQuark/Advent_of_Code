import re

with open('input') as input:
	inp = [line.rstrip() for line in input]

ranges = []
for i, x in enumerate(inp):
	if ("ticket" not in x):
		r = re.findall(r'\d+', x)
		if len(r) > 0:
			ranges += [x for x in range(int(r[0]), int(r[1]) + 1)]
			ranges += [x for x in range(int(r[2]), int(r[3]) + 1)]
	else:
		break

total = 0
for n in range(i + 4, len(inp)):
	for num in re.findall(r'\d+', inp[n]):
		if int(num) not in ranges:
			total += int(num)
print(total)
