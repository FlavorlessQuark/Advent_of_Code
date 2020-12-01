from copy import deepcopy

Lights = []
corners =  {(0,0):1, (0,99):1, (99,99):1, (99,0):1}
def count(x, y):
	test = sum((v,w) in Buffer for v in (x - 1, x , x + 1) for w in (y - 1, y , y + 1) if (v,w) in Buffer if Buffer[(v,w)] == 1 and (v,w) != (x,y))
	return test

with open('input') as input:
	x = 0
	Buffer = {(x,y):0 if char == '.' else 1 for y, line in enumerate(input) for x, char in enumerate(line[:-1])}

	Buffer2 = deepcopy(Buffer)

for i in range(100):
	for x in range(100):
		for y in range (100):
			ct = count(x,y)
			if ct < 2 or ct > 3:
				Buffer2[(x,y)] = 0
			if ct == 3:
				Buffer2[(x,y)] = 1
			Buffer2.update(corners)
	Buffer = deepcopy(Buffer2)
num = sum(Buffer[obj] for obj in Buffer)

print("Solution :", num)
