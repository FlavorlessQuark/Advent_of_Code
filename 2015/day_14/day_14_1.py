from __future__ import division

# name = ""

maximum = 0


with open('input') as input:
	participants = [line.split() for line in input]
for deer in participants:
	cycle = 2503 / (int(deer[6]) + int(deer[13]))
	distance = int(cycle) * int(deer[3]) * int(deer[6])
	distance += (int(deer[3]) * int(deer[6])) if (cycle % 1) * (int(deer[6]) + int(deer[13])) >= int(deer[6]) else int(deer[3]) * cycle % 1
	maximum = max(distance, maximum)

print(maximum)
