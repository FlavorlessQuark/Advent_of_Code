num = 0

def naughty_list(st):
	vowels = 0
	double = False
	if (st.find("ab") != -1 or st.find("cd") != -1 or st.find("pq") != -1 or st.find("xy") != -1):
		return False
	for i in range(0,len(st)):
		if (st[i] == 'a' or st[i] == 'e' or st[i] == 'i' or st[i] == 'o' or st[i] == 'u'):
			vowels += 1
	for i in range(1, len(st) - 1):
		if (( i > 0 and st[i] == st[i - 1]) or (i < len(st) and st[i] == st[i + 1])):
			double = True
			break
	if (vowels < 3):
		return False
	return double
with open('input') as input:
	for line in input:
		if (naughty_list(line) == True):
			num += 1
print("num " + str(num))
