import re

with open('input') as input:
	num = sum(map(int, (e for line in input for e in re.findall(r'-?\d*', line) if len(e) > 0)))
print(num)


# def rm_red(txt):
# 	if 'red' in txt:
# 		return None
# 	return txt
# # total = 0
# lst = map(rm_red, (num for num in json.loads(open('input', 'r').read())))

# # for things in lst:
# num = sum(sum(map(int, (e for e in re.findall(r'-?\d*', str(things)) if len(e) > 0)) for things in lst))
#  ^ While attempting part 2 , found an intersting way to do part 1
