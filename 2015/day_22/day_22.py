with open('input') as input:
	boss = [int(line.split()[-1]) for line in input]

Turns = 50 / boss[1]

# Skipping this one because I can't find a way to do it without runnning a simulation...
