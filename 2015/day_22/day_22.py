import re
from copy import deepcopy

class Player:
	Id = 0
	HP = 50
	Mana = 500
	Used_Mana = 0
	Armor = 0
	Effects = {}

	def next_turn(self, boss):
		player.Armor = 0
		if not bool(self.Effects):
			print("No Effects at the moment")
		for name, val in list(self.Effects.items()):
			val[0] -= 1
			print("Effect", name, "Remains :", val[0])
			val[1](self, boss)
			if val[0] == 0:
				del self.Effects[name]

	def status(self):
		print("Status :", "HP :", self.HP, "| Mana :", self.Mana, "| Armor :", self.Armor, "| Used mana :",self.Used_Mana)

	def spent_mana(self):
		return self.Used_Mana


class Boss:
	HP = 0
	Dmg = 0
	def __init__(self):
		self.HP, self.Dmg = map(int,re.findall(r'\d+', open('input').read()))


def Shield(player, boss):
	player.Armor = 7

def Poison(player, boss):
	boss.HP -= 3

def Recharge(player, boss):
	player.Mana += 101

def Missile(player, boss):
	boss.HP -= 4

def Drain(player, boss):
	boss.HP -= 2
	player.HP += 2


Spells = {
		"Magic Missile":( 53, Missile,	None,		0),
		"Drain": 		( 73, Drain, 	None,		0),
		"Shield":		(113, None, 	Shield, 	6),
		"Poison":		(173, None, 	Poison, 	6),
		"Recharge":		(229, None, 	Recharge, 	5)
}

def use_Spell(player, boss, spell, name):
	player.Mana -= spell[0]
	player.Used_Mana += spell[0]
	print("Player used :", name)
	if spell[1] is None:
		player.Effects[name] = [spell[3], spell[2]]
	else:
		spell[1](player, boss)

Minimum = 1000000

def play_turn(player, boss, spell, name):
	global Minimum

	print("--------Next Turn-------")
	player.next_turn(boss)
	use_Spell(player, boss, spell, name)
	
	print("Boss status :", boss.HP)
	if boss.HP <= 0:
		print("Boss died")
		Minimum = min(player.spent_mana(), Minimum)
		return
	player.HP = max((player.HP + player.Armor) - boss.Dmg, 0)
	player.status()
	if player.HP <= 0:
		print("Player died")
		return
	for x in Spells:
		if x not in player.Effects and player.Mana >= Spells[x][0]:
			play_turn(deepcopy(player), deepcopy(boss), Spells[x], x)

player = Player()

boss= Boss()

# use_Spell(player, boss, Spells["Shield"], "Shield")
for x in Spells:
	if x not in player.Effects and player.Mana >= Spells[x][0]:
		play_turn(deepcopy(player), deepcopy(boss), Spells[x], x)

print(Minimum)
# print(Spells["Drain"])/
