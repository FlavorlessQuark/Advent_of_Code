import numpy as np

goal = 34000000

houses = np.zeros(goal)

for num in xrange(1, goal):
	for i in xrange(0, 50, num):
		houses[i] += num * 11
		if i >= 50:
			break
		if houses[i] >= goal and i > 0:
			break
for x in range(1, goal):
	if houses[x] >= goal:
		print(x)
		break

#Refactor works for day1 but not day2. Somehow the number of presents go down to 0...
#I'm not quite sure why.
