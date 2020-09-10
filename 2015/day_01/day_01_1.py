floor = 0

with open('input') as input:
	while True:
		character = input.read(1)
		if not character:
			break
		if (character == '('):
			floor += 1
		else:
			floor -= 1
print "Floor : " + str(floor)
