import json

total = 0
num = 0
sign = 1
obj = False
ob_str = ""

def str_parse():

with open('input.json') as input:
	for line in input:
		for character in line:

			if obj:

			if (character == '{'):
				obj = True
			if (character == '{'):
				obj = False

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



