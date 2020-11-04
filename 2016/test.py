import itertools

start_file = open('input')
instructions = start_file.read().strip().splitlines()


def swap(x, y, word):
	word = list(word)
	temp = word[x]
	word[x] = word[y]
	word[y] = temp
	return ''.join(word)

def swap_letters(x, y, word):
    return word.replace(x, '?').replace(y, x).replace('?', y)

import re #, os

# read nodes in a dictionary
d_nodes = {}
with open("input", 'r') as f:
    for line in f:
        if line[0] != '/':
            continue
        x, y, size, used, avail, perc = map(int, re.findall(r'\d+', line))
        d_nodes[(x, y)] = {'used': used, 'avail': avail}

lx = max([val[0] for val in d_nodes.keys()])+1
ly = max([val[1] for val in d_nodes.keys()])+1

# puzzle1 - count viable pairs
cnt = 0
vals = list(d_nodes.values())
for i in range(len(vals)):
    for j in range(i+1, len(vals)):
        if vals[i]['used'] != 0 and vals[i]['used'] <= vals[j]['avail']:
            cnt += 1
        if vals[j]['used'] != 0 and vals[j]['used'] <= vals[i]['avail']:
            cnt += 1
print(cnt)
