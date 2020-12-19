import re
#Reminder to self : Need to make these "imaginary" else it recurses and calls add again
class solver(int):
	def __add__(a, b):
		return solver(a.real + b.real)
	def __sub__(a, b):
		return solver(a.real * b.real)

with open('input') as input:
	inp = [re.sub(r"(\d+)", r"solver(\1)", line) for line in input]

lines = [x.replace("*", "-") for x in inp]

print("Solution:", sum(eval(line) for line in lines))
