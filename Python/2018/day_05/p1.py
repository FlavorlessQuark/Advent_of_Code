with open('input') as input:
	inp = [char for line in input for char in line.rstrip()]
total = 0

s = ['0']

for x in inp:
	if x == s[-1].swapcase():
		s.pop()
	else:
		s.append(x)
print(len(s) - 1)
