circuit = {}

instructions = []

def parse(step):
	print("Now parsing" + step)
	for wire_instruction in instructions:
		commands = wire_instruction
		if wire_instruction[len(wire_instruction) - 1] == step:
			break

	wire = commands[len(commands) - 1]
	if len(commands) == 3:
		if commands[0][0] >= '0' and commands[0][0] <= '9':
			circuit[wire] = int(commands[0])
		else:
			if commands[0] not in circuit:
				parse(commands[0])
			circuit[wire] = circuit[commands[0]]
		return

	if commands[0] == "NOT":
		if commands[1] not in circuit:
			parse(commands[1])
		circuit[wire] = 0xffff - circuit[commands[1]]
		return

	if commands[0] not in circuit and (commands[0][0] < '0' or commands[0][0] > '9'):
		parse(commands[0])

	if commands[1] == "RSHIFT":
		circuit[wire] = circuit[commands[0]] >> int(commands[2])
	elif commands[1] == "LSHIFT":
		circuit[wire] = circuit[commands[0]] << int(commands[2])

	elif commands[2] not in circuit:
		parse(commands[2])
	if commands[1] == "AND":
		if commands[0][0] >= '0' and commands[0][0] <= '9':
			circuit[wire] = int(commands[0]) & circuit[commands[2]]
		else:
			circuit[wire] = circuit[commands[0]] & circuit[commands[2]]
	elif commands[1] == "OR":
		circuit[wire] = circuit[commands[0]] | circuit[commands[2]]

with open('input') as input:
	for line in input:
		instructions.append(line.split())
	parse('a')
print(str(circuit.get('a')))
