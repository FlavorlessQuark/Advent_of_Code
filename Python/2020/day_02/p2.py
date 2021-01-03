with open('input') as input:
	inp = [line.split() for line in input]

c = 0
for nums, char, s in inp:
	if char[0] in s:
		x, y = tuple(map(int, nums.split('-')))
		if s[x - 1] != s[y - 1] and (s[x - 1] == char[0] or s[y - 1] == char[0]):
			c += 1
print("Solution : ", c)
