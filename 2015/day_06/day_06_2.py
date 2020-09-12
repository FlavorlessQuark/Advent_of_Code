from array import *
grid = [[0 for i in range(1000)] for i in range(1000)]

def count_lights():
	global grid
	count = 0

	for i in range(0, 999):
		for n in range(0, 999):
				count += grid[i][n]
	return count

def parse(line):
	global grid
	switch = -1

	lst = line.split()
	if (lst[0] == "toggle"):
		switch = 2
	if (lst[1] == "on"):
		switch = 1
	back = lst[len(lst) - 1].split(',')
	front = lst[len(lst) - 3].split(',')
	for i in range(int(front[1]), int(back[1]) + 1 ):
		for n in range(int(front[0]), int(back[0]) + 1):
				grid[n][i] += switch
				if (grid[n][i] < 0):
					grid[n][i] = 0

with open('input') as input:
	for line in input:
		parse(line)
count = count_lights()
print(count)

