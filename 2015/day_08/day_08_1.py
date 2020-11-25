total = 0

with open('input') as input:
	total = sum([len(line.rstrip()) - len(eval(line.rstrip())) for line in input])

print("Solution : ", total)
