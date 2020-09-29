import re

with open('input') as input:
	inp = input.readline()[:-1]

f = re.findall(r'\)', inp)

print len(inp) - (len(f) * 2)
