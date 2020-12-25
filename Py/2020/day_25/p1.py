with open('input') as input:
	a, b = [int(line.rstrip()) for line in input]

s_num = 7
def loop(reach):
	i = 1
	v = 1
	while True:
		v = v * s_num
		v = v % 20201227
		if v == reach:
			return i
		i += 1

c = loop(a)
d = loop(b)
def loop_s(times, s):
	v = 1
	for x in range(times):
		v = v * s
		v = v % 20201227
	return v

print(loop_s(c, b), loop_s(d, a))
