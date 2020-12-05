with open('input') as input:
	inp = [line.rstrip() for line in input]

ids = []
for x in inp:
	ID = "".join(['1' if letter == 'B' or letter == 'R' else '0' for letter in x])
	ids.append(int(ID, 2))
ids.sort()
seat = [i for i in range(ids[0], ids[-1]) if i not in ids]
print("Solution : ", *seat)

