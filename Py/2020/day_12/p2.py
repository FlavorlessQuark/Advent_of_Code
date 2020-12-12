import math

with open('input') as input:
	inp = [(line[0], int(line[1:].rstrip())) for line in input]

dirs = {"N":0, "E":0, "S":0, "W":0}
wdirs = {"N":1, "E":10, "S":0, "W":0}

turns = ["N","E", "S","W"]
curr = 1

for instruction in inp:

	if (instruction[0] == 'L'):
		x = round((wdirs["E"] - wdirs["W"]) * math.cos(instruction[1]) - (wdirs["N"] - wdirs["S"]) * math.sin(instruction[1]), 0)
		y = round((wdirs["E"] - wdirs["W"]) * math.sin(instruction[1]) + (wdirs["N"] - wdirs["S"]) * math.cos(instruction[1]), 0)

		if (x > 0):
			wdirs["E"] = x
			wdirs["W"] = 0
		else:
			wdirs["E"] = 0
			wdirs["W"] = -x
		if (y > 0):
			wdirs["N"] = y
			wdirs["S"] = 0
		else:
			wdirs["N"] = 0
			wdirs["S"] = -y

	elif (instruction[0] == 'R'):
		x = round((wdirs["E"] - wdirs["W"]) * math.cos(-instruction[1]) - (wdirs["N"] - wdirs["S"]) * math.sin(-instruction[1]), 0)
		y = round((wdirs["E"] - wdirs["W"]) * math.sin(-instruction[1]) + (wdirs["N"] - wdirs["S"]) * math.cos(-instruction[1]), 0)
		if (x > 0):
			wdirs["E"] = x
			wdirs["W"] = 0
		else:
			wdirs["E"] = 0
			wdirs["W"] = -x
		if (y > 0):
			wdirs["N"] = y
			wdirs["S"] = 0
		else:
			wdirs["N"] = 0
			wdirs["S"] = -y
	elif (instruction[0] == 'F'):
		for d in turns:
			dirs[d] += wdirs[d] * instruction[1]
			wdirs[d] += dirs[d]
		dirs[turns[curr]] += instruction[1]
	else:
		dirs[instruction[0]] += instruction[1]

wdirs['N'] -= wdirs['S']
wdirs['E'] -= wdirs['W']

wdirs['S'] = 0
wdirs['W'] = 0

print(abs(wdirs['N']) + abs(wdirs['E']))
# print(inp)
