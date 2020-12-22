import re

a,b = open("input").read().rstrip().split("\n\n")

# print(p1)
p1 = [line for line in a.split("\n")]
p2 = [line for line in b.split("\n")]


p1 = p1[1:]
p2 = p2[1:]


w = []

def Recursive_Combat(one, two):
	winner = 0
	r = {}
	while True:
		if tuple(two) in r and tuple(one) == r[tuple(two)]:
			return (True, one)
		r[tuple(one)] = tuple(two)
		a = int(one[0])
		b = int(two[0])

		one.pop(0)
		two.pop(0)
		if a <= len(one) and b <= len(two):
			winner = Recursive_Combat(one[:a], two[:b])[0]
		else:
			winner  = a > b
		if winner == True:
			one.append(a)
			one.append(b)
		else:
			two.append(b)
			two.append(a)
		if not one:
			return (False, two)
		if not two:
			return (True, one)

print(Recursive_Combat(p1, p2))
