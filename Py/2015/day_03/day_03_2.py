houses = []
class San_Rob:
	x = 0
	y = 0

def parse_input(input, person):
	global houses

	key = (person.x, person.y)
	if not key in houses:
		houses.append(key)

	if input == '>':
		person.x += 1
	if input == '<':
		person.x -= 1
	if input == '^':
		person.y += 1
	if input == 'v':
		person.y -= 1

	key = (person.x, person.y)
	if not key in houses:
		houses.append(key)

santa = San_Rob()
rob = San_Rob()

with open('input') as input:
	while 1:
		instruction = input.read(1)
		if not instruction:
			break
		parse_input(instruction, santa)
		instruction = input.read(1)
		if not instruction:
			break
		parse_input(instruction, rob)
print("Solution : " + str(len(houses)))
