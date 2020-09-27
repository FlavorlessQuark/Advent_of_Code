from __future__ import division
import numpy as np

goal = 34000000

houses = np.zeros(goal + 1)

for num in xrange(1, goal + 1):
	for i in xrange(0, goal + 1, num):
		houses[i] += num
		if houses[i] >= goal and i > 0:
			print(i)
			exit()

