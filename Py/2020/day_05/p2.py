with open('input') as input:
	inp = [line.rstrip() for line in input]

ids = []
maximum = 0
minimum = 10000000000
for x in inp:
	row = [n for n in range(128)]
	col = [n for n in range(8)]
	for letter in x:
		if letter == 'F':
			row = row[:len(row) // 2]
		elif letter == 'B':
			row = row[len(row) // 2:]
		if letter == 'R':
			col = col[len(col) // 2:]
		elif letter == 'L':
			col = col[:len(col) // 2]
		ID = row[0] * 8 + col[0]
	maximum = max(ID, maximum)
	minimum = min(ID, minimum)
	ids.append(ID)

seat = [i for i in range(minimum, maximum) if i not in ids]
print("Solution : ", *seat)

