from collections import Counter

with open('input') as input:
	inp = [line.rstrip() for line in input]

twos = 0
threes = 0
for x  in inp:
	c = Counter(x)
	# print(c.values())
	if any([x == 2 for x in c.values()]):
		twos += 1
	if any([x == 3 for x in c.values()]):
		threes += 1

print(twos * threes)
