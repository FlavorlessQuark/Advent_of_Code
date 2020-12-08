with open('input') as input:
	inp = [line for line in input]

x = 0
save = (0, inp[0])
instructions = []
for num, line in enumerate(inp):
	if "nop" in line or "jmp" in line:
		instructions.append(num)

exe = []
for ins in instructions:
	x = 0
	accumulator = 0
	while x >= 0 and x < len(inp):
		exe.append(x)
		if x == ins:
			if "nop" in inp[ins]:
				x += int(inp[x][4:])
			else:
				x += 1
		else:
			if ("acc" in inp[x]):
				accumulator += int(inp[x][3:])
				x += 1
			elif ("nop" in inp[x]):
				x += 1
			else:
				x += int(inp[x][4:])
		if x in exe:
			exe.clear()
			break
	if (x < 0 or x >= len(inp)):
		print("Solution : ", accumulator)
		exit()

