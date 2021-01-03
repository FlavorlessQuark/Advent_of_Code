with open('input') as input:
	inp = [line.rstrip() for line in input]

i = 0
c = 0
for x in inp:
	l = len(x)
	if i >= l:
		i -= l
	if (x[i] == '#'):
		c += 1
	i += 3

print("Solution : ", c)
