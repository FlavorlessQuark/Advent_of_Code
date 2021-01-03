from anytree import Node, RenderTree, DoubleStyle

Happiness = {}
People = []
root = Node("Root")
maximum = 0

def tree_create(current, parent, citylist):
	_node = Node(current, parent=parent)

	_cpcitylst = list(citylist)
	del _cpcitylst[_cpcitylst.index(current)]

	for city in _cpcitylst:
		tree_create(city, _node, _cpcitylst)

def tree_iter(current, parent, total, start):
	global maximum
	global Happiness

	total += Happiness[current.name][parent.name]
	total += Happiness[parent.name][current.name]

	if len(current.children) == 0:
		total += Happiness[current.name][start]
		total += Happiness[start][current.name]
		maximum = max(maximum, total)
		total = 0
	for child in current.children:
		tree_iter(child, current, total, start)


with open('input') as input:
	for line in input:
		line = line[:-2]
		current = line.split()
		if current[0] not in People:
			People.append(current[0])

		gain = int(current[3]) * -1 if current[2] == "lose" else int(current[3])
		if current[0] not in Happiness:
			Happiness[current[0]] = {}
		if "Me" not in Happiness[current[0]]:
			Happiness[current[0]]["Me"] = 0
		Happiness[current[0]][current[10]] = gain

People.append("Me")
Happiness['Me'] = {'Alice':0, 'Bob':0, 'Carol':0, 'David':0, 'Eric':0, 'Frank':0, 'George':0, 'Mallory':0}
for peeps in People:
	tree_create(peeps, root, list(People))
for node in root.children:
	for child in node.children:
		tree_iter(child, node, 0, node.name)
print(str(maximum))
