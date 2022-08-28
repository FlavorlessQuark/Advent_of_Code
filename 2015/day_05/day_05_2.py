import re

pair = re.compile(r'([a-z]).\1')
double = re.compile(r'([a-z][a-z]).*\1')
num = 0

def naughty_list(st):
	return bool(pair.findall(st)) and bool(double.findall(st))

with open('input') as input:
	num = sum([1 for line in input if naughty_list(line)])

print("Solution : ", num)
