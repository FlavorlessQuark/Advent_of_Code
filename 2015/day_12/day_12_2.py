import re
import json

def rm_red(txt):
	if 'red' in txt:
		return 0
	return txt
# total = 0
lst = map(rm_red, (num for num in json.loads(open('input', 'r').read())))

num = 0
for things in lst:
	num += sum(int(e) for e in map(int, (e for e in re.findall(r'-?\d*', str(things)) if len(e) > 0)))
print num

# Could put all of this in  single expressions but :
# 1) that's too much work for too little a reward
# 2) Would be total gibberish
