with open('input') as input:
	inp = [line.split() for line in input]
c = 0
for x in inp:
	if x[1][:1] in x[2]:
		a = x[2].count(x[1][:1])
		b = x[0].split('-')
		s = x[2]
		i = int(b[0])
		n = int(b[1])
		c1 = s[i - 1]
		c2 = s[n - 1]
		if c1 != c2 and (c1 == x[1][:1] or c2 == x[1][:1]):
			c +=1
print(c)
