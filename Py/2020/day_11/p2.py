from copy import deepcopy

with open('input') as input:
	inp = [[char for char in line.rstrip()] for line in input]


dirs = [(0,1), (0,-1), (1, 0), (-1,0), (1,1), (1, -1), (-1, 1), (-1, -1)]
l = len(inp)
ll = len(inp[0])

prev = deepcopy(inp)

while True:
	tmp = deepcopy(prev)
	for y in range(l):
		for x in range(ll):
			occupied = 0
			for d in dirs:
				t_y = y
				t_x = x
				while (0 <= (t_y + d[0]) < l and 0 <= (t_x + d[1]) < ll):
					if (prev[t_y + d[0]][t_x + d[1]] == 'L'):
						break
					elif (prev[t_y + d[0]][t_x + d[1]] == '#'):
						occupied += 1
						break
					t_y +=  d[0]
					t_x +=  d[1]

			if prev[y][x] == '#' and occupied >= 5:
				tmp[y][x] = 'L'
			elif prev[y][x] == 'L' and occupied == 0:
				tmp[y][x] = '#'

	if (prev == tmp):
		c = 0
		for s in tmp:
			c += s.count('#')
		print(c)
		exit()
	prev = deepcopy(tmp)

