import re

a,b = open("input").read().rstrip().split("\n\n")

# print(p1)
p1 = [line for line in a.split("\n")]
p2 = [line for line in b.split("\n")]


p1 = p1[1:]
p2 = p2[1:]
while True:
	if int(p1[0]) > int(p2[0]):
		p1.append(p1[0])
		p1.append(p2[0])
		p1.pop(0)
		p2.pop(0)
	else:
		p2.append(p2[0])
		p2.append(p1[0])
		p1.pop(0)
		p2.pop(0)
	if (len(p2) == 0):
		print(sum([int(x) * (i + 1) for i, x in enumerate(reversed(p1))]))
		# print(p1)
		break
	if (len(p1) == 0):
		print(sum([int(x) * (i + 1) for i, x in enumerate(reversed(p2))]))
		# print(p2)
		break
# with open('input') as input:
# 	inp = [line.rstrip() for line in input]
