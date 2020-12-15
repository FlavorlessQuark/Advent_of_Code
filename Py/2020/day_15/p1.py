import re

inp = [int(x)for x in re.findall(r'(\d+)', open("input").read())]

num = 0
# 0 = last time spoken
# 1 = time before that
l = {}
for i in range(len(inp)):
	if inp[i] not in l:
		l[inp[i]] = [i + 1]
	else:
		l[inp[i]].append(i + 1)
n = inp[i]

for x in range(i + 2, 2021):
	if n not in l:
		l[n] = [x]
		n = 0
	else:
		if len(l[n]) == 1:
			n = 0
			l[n].append(x)
		else:
			n = l[n][-1] - l[n][-2]
			if n not in l:
				l[n] = [x]
			else:
				l[n].append(x)

print(n)
