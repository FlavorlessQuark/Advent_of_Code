with open('input') as input:
	inp = [(line[0], int(line[1:].rstrip())) for line in input]

dirs = {"N":0, "E":0, "S":0, "W":0}

turns = ["N","E","S","W"]
curr = 1
for instruction in inp:
	if (instruction[0] == 'R'):
		curr += instruction[1] // 90
	elif (instruction[0] == 'L'):
		curr -= instruction[1] // 90
	elif (instruction[0] == 'F'):
		dirs[turns[curr % 4]] += instruction[1]
	else:
		dirs[instruction[0]] += instruction[1]

dirs['N'] -= dirs['S']
dirs['E'] -= dirs['W']

print(abs(dirs['N']) + abs(dirs['E']))
