import re
import itertools
from collections import defaultdict, OrderedDict

inp = open('input').read().rstrip().split("\n")

mem = OrderedDict()
for i in inp:
	if "mask" in i:
		mask = i[7:]
	else:
		nums = re.findall(r'\d+', i)
		tmp = format(int(nums[0]), 'b').zfill(36)
		l = list(mask)
		for x, val in enumerate(tmp):
			if l[x] == '0':
				l[x] = tmp[x]
		mem["".join(map(str,l))] = nums[1]

total = 0
final = defaultdict(int)

for key in mem:
		indices = [i for i, x in enumerate(key) if x == "X"]
		comb = [x for x in itertools.product([0,1],repeat=len(indices))]
		for x in comb:
			b_list = list(key)
			for index, val in zip(indices, x):
				b_list[index] = val
			final[int("".join(map(str,b_list)),2)] = mem[key]
			# print(key, int("".join(map(str,b_list)),2), mem[key])


for x in final:
	total += int(final[x])

print(total)
