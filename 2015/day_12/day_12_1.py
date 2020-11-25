import re

with open('input') as input:
	num = sum(map(int, (e for line in input for e in re.findall(r'-?\d*', line) if len(e) > 0)))
print(num)
