# import regex
import re

inp = open("input").read()

r, strs = inp.split("\n\n")
strs = strs.split("\n")
r = r.split("\n")
rules = {}

def recurse(entry):
	if entry == ' 42 | 42 8':
		return '(' + recurse('42') + ')+'
	elif (entry == ' 42 31 | 42 11 31'):
		return '(' + recurse('42') + recurse('31') + '|' + '(' + recurse('42') + 'X' + ')X' + recurse('31') + 'X'
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

rules['11'] =" 42 31 | 42 11 31"
rules['8'] =" 42 | 42 8"

rules['0'] = recurse(rules['0'])

rules['0'] = "^" + rules['0'].replace("\"", "") + "$"

total = 0
for i in range(1,3):
	e = rules['0'].replace('X', '{'+ str(i) + '}')
	total += sum([1 for x in strs if re.findall(e, x)])
# for s in strs:
print(total)
# 	print(re.findall(rules['0'], s.rstrip()))
