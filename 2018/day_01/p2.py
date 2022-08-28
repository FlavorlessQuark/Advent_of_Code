import re
with open('input') as input:
	inp = [line.rstrip() for line in input]

ts = set([0])
total = 0
while True:
	for x in inp:
		total += int(x)
		if total in ts:
			print(total)
			exit()
		ts.add(total)
