with open('input') as input:
	inp = [line.rstrip() for line in input]

for x in inp:
	for y in inp:
		diff = 0
		for char_a, char_b in zip(x, y):
			if char_a != char_b:
				if diff == 1:
					diff += 1
					break
				diff += 1
		if diff == 1:
			print("".join([a for a,  b in zip(x, y) if a == b]))
			exit()
