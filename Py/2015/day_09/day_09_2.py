from anytree import Node, RenderTree, DoubleStyle

Distance = {}
Cities = []
root = Node("Root")
minimum = 0

def tree_create(current, parent, citylist):
	_node = Node(current, parent=parent)

	_cpcitylst = list(citylist)
	del _cpcitylst[_cpcitylst.index(current)]

	for city in _cpcitylst:
		tree_create(city, _node, _cpcitylst)

def tree_iter(current, parent, distance):
	global minimum

	if current.name in Distance and parent.name in Distance[current.name]:
		distance += int(Distance[current.name][parent.name])
	elif parent.name in Distance and current.name in Distance[parent.name]:
		distance += int(Distance[parent.name][current.name])
	if len(current.children) == 0:
		minimum = max(minimum, distance)
	for child in current.children:
		tree_iter(child, current, distance)

with open('input') as input:

	for line in input:
		current = line.split()
		if current[0] not in Cities:
			Cities.append(current[0])
		if current[2] not in Cities:
			Cities.append(current[2])

		if current[0] not in Distance and current[2] not in Distance:
			Distance[current[0]] = {current[2]: current[4]}
		else:
			for x in [0,2]:
				if current[x] in Distance:
					y = 2 if x == 0 else 0
					Distance[current[x]][current[y]] = current[4]


	for city in Cities:
		tree_create(city, root, list(Cities))
	tree_iter(root, root, 0)
	print("Solution : ", str(minimum))
