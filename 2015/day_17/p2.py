import itertools


with open('input') as input:
	nums = [int(line[:-1]) for line in input]

sol = [x for y in range(len(nums)) for x in itertools.combinations(nums, y)  if sum(x) == 150]

minimum = min(len(x) for x in sol)

sol = [x for x in itertools.combinations(nums, minimum)  if sum(x) == 150]
print("Solution :", len(sol))
