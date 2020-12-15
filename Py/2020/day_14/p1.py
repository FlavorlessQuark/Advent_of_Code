import re

inp = open('input').read().rstrip().split("\n")

mem = {}
for i in inp:
	if "mask" in i:
		mask = i[7:]
	else:
		nums = re.findall(r'\d+', i)
		tmp = format(int(nums[1]), 'b').zfill(36)
		l = list(tmp)
		for x, val in enumerate(mask):
			if val == '1':
				l[x] = 1
		mem[nums[0]] = int("".join(map(str,l)),2)

total = 0

for key in mem:
		total += mem[key]

print(total)
