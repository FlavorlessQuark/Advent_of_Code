circuit = {}
gate = []

def parse(inpu):
	global gate
	data = inpu.split()
	last = data[len(data) - 1]

	if wire in circuit:
		return False
	if (inpu[0] >= '0' and inpu[0] <='9'):
		circuit[wire] = int(data[0])
		return True

	if data[0] == "NOT":
		if data[1] not in circuit:
			if inpu not in gate:
				gate.append(inpu)
			return False
		circuit[wire] = ~circuit[data[1]]
		if (circuit[wire] < 0):
			circuit[wire] += 65536

	elif data[0] not in circuit:
		if (inpu not in gate):
			gate.append(inpu)
		return False
	elif data[1] == "RSHIFT":
		circuit[wire] = circuit[data[0]] >> int(data[2])
	elif data[1] == "LSHIFT":
		circuit[wire] = circuit[data[0]] << int(data[2])

	if (len(data) == 3):
		circuit[wire] = circuit[data[0]]
	elif data[2] not in circuit:
		if (inpu not in gate):
			gate.append(inpu)
		return False
	elif data[1] == "OR":
		circuit[wire] = circuit[data[0]] | circuit[data[2]]
	elif data[1] == "AND":
		circuit[wire] = circuit[data[0]] & circuit[data[2]]
	if circuit[wire] > 65535:
		circuit[wire] -= 65535
	if inpu in gate:
		gate.remove(inpu)
	return True

with open('input') as input:
	for line in input:
		for thing in gate:
			parse(thing)
		parse(line)
print(str(circuit.get('a')))
