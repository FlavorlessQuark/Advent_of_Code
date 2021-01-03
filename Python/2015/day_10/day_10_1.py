import re

with open("input") as input:
	num_str = input.readline()[:-1]

for i in range(0, 40):
	exp = re.compile(r'((\d)\2*)')
	num_str = ''.join(str(len(ex[0])) + str(ex[1]) for ex in re.findall(exp, num_str))
print("Solution : ", len(num_str))

