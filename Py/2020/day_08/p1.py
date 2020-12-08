accumulator = 0

exe = []
with open('input') as input:
	inp = [line for line in input]

x = 0
while x >=0 and x < len(inp):
	if x in exe:
		print("Solution : ", accumulator)
		exit()
	else:
		exe.append(x)
		if ("acc" in inp[x]):
			accumulator += int(inp[x][3:])
			x += 1
		if ("nop" in inp[x]):
			x += 1
		elif ("jmp" in inp[x]):
			x += int(inp[x][4:])

