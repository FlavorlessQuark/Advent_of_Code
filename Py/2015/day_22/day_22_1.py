import re
import itertools
from copy import deepcopy
import time

class Player:
	HP = 0
	Mana = 0
	Used_Mana = 0
	Armor = 0
	Effects = {}
	Log = []
	ID = 0

	def __init__(self):
		self.HP = 50
		self.Mana = 500
		self.Armor = 0
		self.Effects = {}
		self.Log = []

	def apply_effect(self, boss):
		self.Armor = 0
		for name, val in list(self.Effects.items()):
			val[1](self, boss)
			val[0] -= 1
			# print("Effect", name, "Remains :", val[0])
			if val[0] == 0:
				del self.Effects[name]

	def status(self):
		print("Player ", self.ID,":", "HP :", self.HP, "| Mana :", self.Mana, "| Armor :", self.Armor, "| Used mana :",self.Used_Mana)

	def spent_mana(self):
		return self.Used_Mana


class Boss:
	HP = 0
	Dmg = 0
	def __init__(self):
		self.HP, self.Dmg = 71, 10
		# self.HP, self.Dmg = map(int,re.findall(r'\d+', open('input').read()))

	# def status(self):
		# print("Boss : | HP", self.HP, "| Dmg :", self.Dmg)

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

Minimum = 1000000

def use_Spell(player, boss, name):

	player.Mana -= Spells[name][0]
	player.Used_Mana += Spells[name][0]

	if Spells[name][1] == None:
		player.Effects[name] = [Spells[name][3] , Spells[name][2]]
	else:
		Spells[name][1](player, boss)

def check_end(player, boss):
	global Minimum

	if player.HP <= 0:
		return -1
	if boss.HP <= 0:
		print("BOSS DIED")
		print(player.Log, player.Used_Mana)
		Minimum = min(Minimum, player.Used_Mana)
		return 1
	if player.Used_Mana >= Minimum:
		return -1
	return 0

def player_turn(player, boss, spell):

	player.apply_effect(boss)
	if check_end(player, boss) != 0:
		return 1
	if (player.Mana >= Spells[spell][0]):
		use_Spell(player, boss, spell)
	else:
		return 1
	if check_end(player, boss) != 0:
		return 1
	return 0

def boss_turn(player, boss):
	player.apply_effect(boss)
	if check_end(player, boss) != 0:
		return 1

	player.HP -= max((boss.Dmg - player.Armor), 1)

	if check_end(player, boss) != 0:
		return 1
	return 0

def turn(player, boss, spell):
	player.Log.append(spell)

	if player_turn(player, boss, spell) != 0:
		return -1
	if boss_turn(player, boss) != 0:
		return -1
	return 0


combs = [x for x in itertools.product(Spells,repeat=15) if (x[0] != "Magic Missile" and x[0] != "Recharge")]
t = []
for n, way in enumerate(combs):
	player = Player()
	boss = Boss()
	success = False
	player.ID = n
	for i, spell in enumerate(way):
		if turn(player, boss, spell) != 0:
			break
	del player
	del boss
print("Solution : ", Minimum)
