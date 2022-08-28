import re

inp = open("input").read()

r, strs = inp.split("\n\n")
strs = strs.split("\n")
r = r.split("\n")
rules = {}

def recurse(entry):
	final = ""
	ors = entry.split("|")
	for x in ors:
		rs = re.findall(r'\d+', x)
		for y in rs:
			final += recurse(rules[y])
		if len(rs) > 0:
			final = "(" + final + ")|"
	final = final[:-1]
	return final if len(final) > 0 else entry


for x in r:
	y , c = x.split(":")
	rules[y] = c.strip()

rules['0'] = recurse(rules['0'])
rules['0'] = "^" + rules['0'].replace("\"", "") + "$"

print("Solution:", sum([1 for x in strs if re.findall(rules['0'], x)]))

