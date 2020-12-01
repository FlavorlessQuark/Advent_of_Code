circuit = {}
parser = {
			"RSHIFT":">>",
			"LSHIFT":"<<",
			"OR":"|",
			"AND":"&"
}
instructions = []

def parse(step):
	for wire_instruction in instructions:
		commands = wire_instruction
		if wire_instruction[-1] == step:
			break

	wire = commands[- 1]
	if len(commands) == 3:
		if str.isdigit(commands[0]):
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

	if commands[0] not in circuit and not str.isdigit(commands[0]):
		parse(commands[0])
	if not str.isdigit(commands[2]) and commands[2] not in circuit:
		parse(commands[2])

	arg1 = commands[0] if str.isdigit(commands[0]) else str(circuit[commands[0]])
	arg2 = commands[2] if str.isdigit(commands[2]) else str(circuit[commands[2]])

	circuit[wire] = eval(arg1 + parser[commands[1]] + arg2)

with open('input') as input:
	instructions = [line.split() for line in input]
parse('a')
print("Solution : ", circuit.get('a'))
