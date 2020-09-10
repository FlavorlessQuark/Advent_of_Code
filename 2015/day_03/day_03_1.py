houses = {}
class San_Rob:
	x = 0
	y = 0

def parse_input(input, person):
	global houses
	#global pos_x
	#global pos_y

	key = (str(person.x) + "_" + str(person.y))
	if not key in houses:
		houses[key] = 1
	if input == '>':
		person.x += 1
	if input == '<':
		person.x -= 1
	if input == '^':
		person.y += 1
	if input == 'v':
		person.y -= 1
	key = (str(person.x) + "_" + str(person.y))
	if not key in houses:
		houses[key] = 1

santa = San_Rob()
with open('input') as input:
	while 1:
		instruction = input.read(1)
		if not instruction:
			break
		parse_input(instruction, santa)
	#	instruction = input.read(1)
	#	if not instruction:
	#		break
	#	parse_input(instruction, rob_pos_x,rob_pos_y)
print("houses " + str(len(houses)))
