from anytree import AnyNode, RenderTree, PreOrderIter
from collections import defaultdict


Distance = {}
Cities = []
root = AnyNode(id="Root")
minimum = 0

def tree_create(current, parent, citylist):
	_node = AnyNode(id=current, parent=parent)
	del citylist[citylist.index(current)]
	_cpcitylst = citylist
	for city in citylist:
		tree_create(city, _node, _cpcitylst)


def tree_traverse(dist, prev):
	global root
	global minimum

	for node in PreOrderIter(root):
		


with open('test') as input:
	# _cities = [line.split()[x] for line in input for x in [0,2]]
	# [Cities.append(y) for y in _cities if y not in Cities]
	for line in input:
		current = line.split()
		if current[0] not in Cities:
			Cities.append(current[0])
		if current[2] not in Cities:
			Cities.append(current[2])

		if current[0] not in Distance and current[2] not in Distance:
			Distance[current[0]] = {current[2]: current[4]}
			minimum += int(current[4])
		else:
			for x in [0,2]:
				if current[x] in Distance:
					minimum += int(current[4])
					y = 2 if x == 0 else 0
					# _d = {[current[y] = current[4]}
					Distance[current[x]][current[y]] = current[4]

	for city in Cities:
		tree_create(city, root, Cities)
	tree_traverse()
	print(Cities)
	print(Distance)
	#print(RenderTree("Root"))
