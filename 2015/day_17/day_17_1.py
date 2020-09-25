import itertools

nums = []
combinations = 0

def solver(input_num):
	global combinations

	minimum = 0
	ination = 0
	for i in xrange(0, len(input_num) - 1):
		for comb in itertools.combinations(input_num, i):
			if sum(comb) == 25:
				if ((minimum != len(comb))):
					ination = 0

				minimum = len(comb)
				ination += 1


	print(str(minimum))

with open('test') as input:
	nums = [int(line[:-1]) for line in input]

solver(nums)

print(str(combinations))

