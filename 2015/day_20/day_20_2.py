import numpy as np

goal = 34000000

houses = np.zeros(goal)

for num in range(1, goal):
	for i in range(0, 50, num):
		houses[i] += num * 11
		if i >= 50:
			break
		if houses[i] >= goal and i > 0:
			break
for x in range(1, goal):
	if houses[x] >= goal:
		print(x)
		break

