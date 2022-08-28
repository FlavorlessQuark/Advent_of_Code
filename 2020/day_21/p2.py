import re
from collections import defaultdict

foods = defaultdict(list)
ing = set()
ingre = []

with open('input') as input:
	inp = [line.rstrip() for line in input]

for line in inp:
	line = line.replace(')', "")
	line = line.replace(',', " ")
	split = line.split('(')
	ingredients = split[0].split()
	for i in ingredients:
		ing.add(i)
		ingre.append(i)
	if len(split) > 1:
		allergens = split[1].split()
		for a in allergens[1:]:
			foods[a].append(ingredients)

final = list(ing)
dangerous = defaultdict(list)
for x in ing:
	for k, v in foods.items():
		if all([x in i for i in v]):
			dangerous[k].append(x)

for k,v in dangerous.items():
	print(k, v)
# s = sorted([('fish','dzqlq'),('eggs','rpf'),('wheat','bltzkxx'),('sesame','xbdh'),('peanuts','bltrbvz'),('shellfish','spql'),('dairy','spcqmzfg'),('nuts','pflk')])

# [print([x[1] for x in s], sep=',')]
# spcqmzfg,rpf,dzqlq,pflk,bltrbvz,xbdh,spql,bltzkxx
