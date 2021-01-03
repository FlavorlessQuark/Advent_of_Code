with open('input') as input:
	inp = [int(c)for line in input for c in line.rstrip()]

# print(inp)

i = 0
l = len(inp)
m = min(inp)
ma = max(inp)
for _ in range(10000000):
	c = int(inp[i])

	hold = []
	lst = inp.copy()
	save = int(inp[i])

	for x in range(1, 4):
		select = i + x
		if select >= l:
			select -= l
		hold.append(lst[select])
		inp.pop(inp.index(lst[select]))
	c -= 1
	if c < m:
		c = ma
	while c in hold:
		c -= 1
		if c < m:
			c = ma
	index = inp.index(c)
	inp = inp[:(index + 1)] + hold + inp[(index + 1):]
	i = inp.index(save)
	i += 1
	if i == len(inp):
		i = 0
print(inp)
