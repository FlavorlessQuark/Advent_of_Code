import re

vowels = re.compile(r"[aeiou]")
repeat = re.compile(r'([a-z])\1')
forbidden = re.compile(r'.*(pq|cd|xy|ab).*')

def naughty_list(st):
	return len(vowels.findall(st)) >= 3 and repeat.findall(st) and not forbidden.match(st)

with open('input') as input:
	num = sum([1 for line in input if naughty_list(line)])
print("Solution : " + str(num))
