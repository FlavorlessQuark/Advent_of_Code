floor = 0
count = 0

with open('input') as input:
	line = input.readline()[:-1]

for char in line:
	floor += 1 if char == '(' else -1
	count += 1
	if floor == -1:
		break
print("Solution : ", count)
