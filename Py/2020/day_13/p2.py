with open('input') as input:
	inp = [line.rstrip() for line in input]

n = int(inp[0])
x = 1
start = 0

ids = [(i, int(val))for i, val in enumerate(inp[1].split(',')) if val != "x"]

for y in ids:
    while (start + y[0]) % y[1] != 0:
        start += x
    x *= y[1]
print(start)
