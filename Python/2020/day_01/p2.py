with open('input') as input:
	inp = [int(line.rstrip()) for line in input]

for x in inp:
	for y in inp:
		for w in inp:
			if x + y  + w == 2020:
				print("Solution :", x * y * w)
				exit()
