import re

d = {}

def get_gold(key):
	if ("shiny gold" in d[key]):
		return 1
	for color in d[key]:
		if get_gold(color) == 1:
			return 1
	return 0

with open('input') as input:
	inp = [line for line in input]

for line in inp:
	color = re.findall('^\w+ \w+', line)
	if(not "".join(color) in d and "shiny gold" not in "".join(color)):
		d["".join(color)] = re.findall(r'(?<=\d )\w+ \w+',line)

count = 0
for key in d:
	count += get_gold(key)

print("Solution : ", count)
