import itertools
import math

Weapons ={(8,4, 0),
		(10, 5, 0),
		(25, 6, 0),
		(40, 7, 0),
		(74, 8, 0)}

Armor = {(0,0,0),
(13,0, 1),
( 31, 0, 2),
( 53, 0, 3),
( 75, 0, 4),
(102, 0, 5)}

Rings ={
(0,0,0),
(0,0,0),
(25,1, 0),
(50, 2, 0),
(100, 3, 0),
(20, 0, 1),
(40, 0, 2),
(80, 0, 3)}

minimum = 1000000
with open('input') as input:
	boss = [int(line.split()[-1]) for line in input]

# r = itertools.combinations(Rings,2)
for weapon in Weapons:
	for armour in Armor:
		d_total = weapon[1] - boss[2]
		a_total = boss[1] - armour[2]
		a_total = max(a_total, 1)
		d_total = max(d_total, 1)
		cost = weapon[0] + armour[0]
		if (boss[0] / d_total) < (100 / a_total):
			minimum = min(minimum, cost)
		for r1,r2 in itertools.product(Rings,repeat=2):
			if (r1 is not r2):
				# print(r1,r2)
				hero_damage = r1[1] + r2[1] + weapon[1] - boss[2]
				boss_damage = max((boss[1] - (r1[2] + r2[2] + armour[2])), 1)
				cost = weapon[0] + armour[0] + r1[0] + r2[0]
				if (boss[0] / max(1, hero_damage)) < (100 / max(1,boss_damage)):
					minimum = min(minimum, cost)
print(minimum)
