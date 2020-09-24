import re
from collections import defaultdict

Sues = {}
pattern = re.compile(r'[a-z]+?: \d+')
Sue_Num = re.compile(r'\d+:')

AuntSue = {'children': 3,
			'cats': 7,
			'samoyeds': 2,
			'pomeranians': 3,
			'akitas': 0,
			'vizslas': 0,
			'goldfish': 5,
			'trees': 3,
			'cars': 2,
			'perfumes':1
}

MatchMaker = lambda x, y: AuntSue[x] == y

with open('input') as input:
	for line in input:
		tmp = pattern.findall(line)

		Sues[Sue_Num.findall(line)[0][:-1]] = {attr.split()[0][:-1]:int(attr.split()[1]) for attr in tmp}

	# if (all(MatchMaker(attr, Sues[str(x)][attr]) for x in xrange(0, 2) for attr in  Sues[str(x)])):
	# 	print(str(x))
	for x in xrange(1, 501):
		match = True
		for attr in Sues[str(x)]:
			if AuntSue[attr] != Sues[str(x)][attr]:
				# print("AUnt sue " + str(AuntSue[attr]) + " Sue " + str(Sues[str(x)][attr]))
				match = False
		if match:
			print(attr + str(x))


