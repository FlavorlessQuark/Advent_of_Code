import re

d = {}

count = 0
def get_bags(key):
	total = 1
	for num, val in d[key]:
		total += int(num) * get_bags(val)
	return total

with open('input') as input:
	inp = [line for line in input]

for line in inp:
	color = re.findall('^\w+ \w+', line)
	if not "".join(color) in d:
		d["".join(color)] = re.findall(r'(\d+) (\w+ \w+)',line)

count += get_bags("shiny gold")
print("Solution : ", count - 1)
