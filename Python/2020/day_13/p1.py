with open('input') as input:
	inp = [line for line in input]

n = int(inp[0])

t = [int(c) for c in inp[1].split(',') if c != 'x']

m = [[x * int(n / x), x] for x in t]

for x in m:
	if x[0] < n:
		x[0] += x[1]

earliest = min(m)

print((earliest[0] - n) * earliest[1])
