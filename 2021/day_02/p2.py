
h = 0
d = 0
ai =0

with open('input') as input:
	inp = [line for line in input]


for a in inp:
	s, n = a.split(" ")
	if (s[0] == "f"):
		h += int(n)
		d += ai * int(n)
	if (s[0] == "d"):
		ai += int(n)

	if (s[0] == "u"):
		ai -= int(n)


print(d * h)
