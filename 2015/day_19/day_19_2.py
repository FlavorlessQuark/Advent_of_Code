import re

with open('input') as input:
	lines = [line for line in input]

replacements = {name for line in lines[:-2] for name, rep in re.findall(r'(\w+) => (\w+)', line)}
molecule = lines[-1].rstrip()

step = 0

y = molecule.count("Y")

molecule = molecule.replace("Ar", "|")
molecule = molecule.replace("Rn", "|")
molecule = molecule.replace("Y", "-")

chunk = sum(1 for x in molecule if x.isupper())

print("Solution :", (chunk + y) - y * 2 - 1)
