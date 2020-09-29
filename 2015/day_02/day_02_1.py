import re
import itertools

get = lambda x:

with open('input') as input:
	txt = [line[:-1] for line in input]
dicts = {e:[a for a in re.findall(r'\d*', txt[e]) if len(a) > 0] for e, stuff in  enumerate(txt)}

num = [a for a in list(comb for e in dicts for comb in itertools.combinations(dicts[e], 2))]
tot = sum(map(get,num))
