with open('input') as input:
	file=  [int(line.rstrip()) for line in input]

x = 25
while (x < len(file)):
	add = False
	for y in range(x - 25, x):
		for z in range(y, x):
			if file[z] + file[y] == file[x]:
				add = True
	if add == False:
		print("Solution : ", file[x])
		exit()
	x += 1

