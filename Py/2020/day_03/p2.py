with open('input') as input:
	inp = [line.rstrip() for line in input]

lst = [(1,1), (3,1), (5, 1), (7, 1), (1, 2)]
l = len(inp)

total = 1
for steps in lst:
	i = 0
	n = 0
	c = 0
	while n < l:
		if i >= len(inp[n]):
			i -= len(inp[n])
		if (inp[n][i] == '#'):
			c += 1
		i += steps[0]
		n += steps[1]
	total *= c

print("Solution : ", total)
