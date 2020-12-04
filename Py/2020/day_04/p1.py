import re

exp = re.compile(r'(\d+)')

fields = ["byr", "iyr","eyr","hgt","hcl","ecl","pid", "cid"]

inpu= open('input').read()

inp = inpu.split("\n\n")
count = 0
for x in inp:
	tmp = 0
	f = re.findall(r'\w+:', x)
	for y in fields:
		if y + ":" in f:
			tmp += 1
	if "cid:" not in f:
		tmp += 1
	if tmp == 8:
		count += 1
print(count)



