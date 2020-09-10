floor = 0
count = 0

with open('input') as input:
	while True:
		character = input.read(1)
		if not character:
			break
		if (character == '('):
			floor += 1
		if (character == ')'):
			floor -= 1
		count += 1
		if (floor == -1):
			break
print "Character : " + str(count)
