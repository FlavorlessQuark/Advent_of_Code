import re

with open('input') as input:
	lines = [line for line in input]

replacements = [(name, rep) for line in lines[:-2] for name, rep in re.findall(r'(\w+) => (\w+)', line)]
molecule = lines[-1].rstrip()
distinct = set()
for name, rep in replacements:
	i = -1
	while True:
		i = molecule.find(name, i + 1)
		if i == - 1:
			break
		distinct.add((molecule[:i] + rep + molecule[i + len(name):]))
print("Solution :", len(distinct))
