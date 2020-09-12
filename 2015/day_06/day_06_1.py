from array import *
grid = [[0 for i in range(1000)] for i in range(1000)]

def count_lights():
	global grid
	count = 0

	for i in range(0, 999):
		for n in range(0, 999):
			if (grid[i][n] == 1):
				count += 1
	return count

def parse(line):
	global grid
	switch = 0

	lst = line.split()
	if (lst[0] == "toggle"):
		switch = 2
	if (lst[1] == "on"):
		switch = 1
	back = lst[len(lst) - 1].split(',')
	front = lst[len(lst) - 3].split(',')
	for i in range(int(front[1]), int(back[1]) + 1 ):
		for n in range(int(front[0]), int(back[0]) + 1):
			if (switch == 2):
				if (grid[n][i] == 0):
					grid[n][i] = 1
				else:
					grid[n][i] = 0
			else:
				grid[n][i] = switch

with open('input') as input:
	for line in input:
		parse(line)
count = count_lights()
print(count)

