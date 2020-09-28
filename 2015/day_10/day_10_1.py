import re

# def count(str)
# {
# }

with open("input") as input:
	num_str = [int(char) for line in input for char in line[:-1]]

exp = re.compile(r'\d')
# for i in range(0,3):
	# re.sub()
# print(num_str)
