houses = []
x = 0
y = 0

def parse_input(input):
	global houses
	global x
	global y

	key = (x,y)
	if not key in houses:
		houses.append(key)
	if input == '>':
		x += 1
	if input == '<':
		x -= 1
	if input == '^':
		y += 1
	if input == 'v':
		y -= 1

with open('input') as input:
	[parse_input(char) for line in input for char in line]

print("Solution : " + str(len(houses)))
