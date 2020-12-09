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
		break
	x += 1

num = file[x]
ceil = x
for x in range(ceil):
	for total_len in range(x, ceil):
		n = [file[y] for y in range(x, total_len)]
		if sum(n) == num:
			print(max(n) + min(n))
			exit()

# n.sort()


