from copy import copy



with open('input') as input:
	inp = [int(c)for line in input for c in line.rstrip()]

head = Linked(None, None)
inp += [c for c in range(max(inp), 1000001)]
it = {}

p = None
for x in inp:
	head = Linked( x, None)
	it[x] = copy(head)
	if p:
		p.n = it[x]
	p = it[x]
	# head = head.n
last = it[inp[-1]]
first = it[inp[0]]

last.n = first
first.prev = last

m = min(inp)
ma = max(inp)

head = it[inp[0]]
for _ in range(10000):
	c = int(head.curr)

	hold = []
	start = head
	tmp = head
	for _ in range(0, 3):
		hold.append(tmp.curr)
		tmp = tmp.n
	c -= 1
	if c < m:
		c = ma
	while c in hold:
		c -= 1
		if c < m:
			c = ma
	past = it[c].n
	start.n = tmp
	it[c].n = start
	head = head.n

# print(it[1])
prev = it[3].n
while prev.curr != 1:
	print(prev)
	prev = prev.n

print(it[1].n * it[1].n.n)
