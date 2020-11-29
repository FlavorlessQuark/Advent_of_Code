registers = {
	'a' : 0,
	'b' : 0,
	'i' : 0,
}

def jmp():
	global registers

	registers['i'] += int(instructions[registers['i']][1])

def inc():
	global registers

	registers[instructions[registers['i']][1]] += 1
	registers['i'] += 1

def hlf():
	global registers

	registers[instructions[registers['i']][1]] /= 2
	registers['i'] += 1

def tpl():
	global registers

	registers[instructions[registers['i']][1]] *= 3
	registers['i'] += 1

def jie():
	global registers

	if  registers[instructions[registers['i']][1][0]] % 2  == 0:
		registers['i'] += int(instructions[registers['i']][2])
	else:
		registers['i'] += 1

def jio():
	global registers

	if  registers[instructions[registers['i']][1][0]] == 1:
		registers['i'] += int(instructions[registers['i']][2])
	else:
		registers['i'] += 1


operations = {
	'jmp' : jmp,
	'jio' : jio,
	'inc' : inc,
	'tpl' : tpl,
	'hlf' : hlf,
	'jie' : jie
}

with open('input') as input:
	instructions = [line.split() for line in input]

maximum = len(instructions)

while registers['i'] >= 0 and registers['i'] < maximum:
	operations[instructions[registers['i']][0]]()

print("Solution :", registers['b'])
