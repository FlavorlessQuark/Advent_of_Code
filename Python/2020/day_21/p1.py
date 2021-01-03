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
al =  []
for x in ing:
	for k, v in foods.items():
		if all([x in i for i in v]):
			if x in final:
				al.append(x)
				del final[final.index(x)]

print(final)
# print(sum([ingre.count(x) for x in final]))
