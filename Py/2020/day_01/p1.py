with open('input') as input:
	inp = [int(line.rstrip()) for line in input]

for x in inp:
	for y in inp:
		print("Solution :", x * y)
		exit()
