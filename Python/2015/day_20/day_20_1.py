import sys
import numpy as np

goal = 34000000

houses = np.zeros(goal)

for num in range(1, goal / 10):
	for i in range(0, goal / 10, num):
		houses[i] += num * 10
		if houses[i] >= goal and i > 0:
			break

for x in range(0, goal):
	if houses[x] >= goal and x > 0:
		print(x)
		sys.exit(0)
