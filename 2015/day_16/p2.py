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

MatchMaker = lambda x, y: AuntSue[x] < y if (x == "tree" or x == "cat") else (AuntSue[x] > y if (x == "pomeranians" or x == "goldfish") else AuntSue[x] == y)

with open('input') as input:
	for line in input:
		tmp = pattern.findall(line)
		Sues[Sue_Num.findall(line)[0][:-1]] = {attr.split()[0][:-1]:int(attr.split()[1]) for attr in tmp}

winners  = [sue_id if all([MatchMaker(attr, Sues[sue_id][attr]) for attr in Sues[sue_id]]) else "" for sue_id in Sues]

print("Solution :", winners)


