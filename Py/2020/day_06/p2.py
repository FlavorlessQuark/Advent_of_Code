inp= open('input').read().rstrip()

alpha = ["a","b","c","d", "e","f", "g", "h", "i", "j","k", "l","m","n","o","p","q","r","s", "t","u","v","w","x","y","z"]

s = 0
inpu = inp.split("\n")
for x in inpu:
	line = x.split("\n")
	for letter in alpha:
		if all([letter in z for z in line ]):
			s += 1
print("Solution : ", alpha)
