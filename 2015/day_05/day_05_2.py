
num = 0

def naughty_list(st):
	pair = 0
	double = False
	for i in range(0,len(st) - 1):
		for n in range(i + 2, len(st)):
			if (st[n] ==  st[i] and st[n + 1] == st[i + 1]):
				pair += 1
	for i in range(2, len(st) - 2):
		if ((st[i] == st[i - 2]) or st[i] == st[i + 2]):
			double = True
			break
	if (pair < 1):
		print("no pair")
		return False
	return double
with open('input') as input:
	for line in input:
		if (naughty_list(line) == True):
			num += 1
print("num " + str(num))
