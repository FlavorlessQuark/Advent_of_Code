inp= open('input').read().rstrip()

alpha = ["a","b","c","d", "e","f", "g", "h", "i", "j","k", "l","m","n","o","p","q","r","s", "t","u","v","w","x","y","z"]

s = 0
inpu = inp.split("\n\n")
for x in inpu:
	tot = sum(1 for y in alpha if y in x)
	s +=tot

print("Solution : ", s)
