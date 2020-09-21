import json

total = 0
num = 0
sign = 1
with open('input.json') as input:
	for line in input:
		for character in line:
			if (character == '-'):
				sign = -1
			elif character.isdigit():
				num *= 10
				num += int(character)
			else:
				total += (num  * sign)
				sign = 1
				num = 0

print(str(total))



