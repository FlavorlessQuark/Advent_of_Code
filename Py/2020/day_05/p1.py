with open('input') as input:
	inp = [line.rstrip() for line in input]

maximum = 0
for x in inp:
	ids = "".join(['1' if letter == 'B' or letter == 'R' else '0' for letter in x])
	maximum = max(int(ids, 2), maximum)
print("Solution : ", maximum)
