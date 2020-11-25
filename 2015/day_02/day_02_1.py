import re
from itertools import combinations as comb

get_slack =	lambda x : (x[0] * x[1])
mult =		lambda x : get_slack(x) * 2

with open('input') as input:
	txt = [line[:-1] for line in input]

presents =  {key : [int(val) for val in re.findall(r'\d*', txt[key]) if len(val) > 0] for key, _ in  enumerate(txt)}
wrap = [area for value in presents for area in comb(presents[value], 2)]

slack = [get_slack(sorted(presents[x])) for x in presents]

print("Solution : ", sum(map(mult, wrap)) + sum(slack))
