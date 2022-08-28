with open('input') as input:
	inp = [char for line in input for char in line.rstrip()]

alpha = [chr(c) for c in range(ord('a'), ord('z') + 1)]
def react(y):
	s = ['0']
	# print(y)
	for x in y:
		if x == s[-1].swapcase():
			s.pop()
		else:
			s.append(x)
	return len(s) - 1

print(min([react([x for x in inp if x != y and x != y.swapcase()]) for y in alpha]))
