alphabet = ['a','b','c','d','e','f','g','h','j','k','m','n','p','q','r','s', 't','u','v','w','x','y','z']

def next_passw(indices):
	while True:
		for i, _ in reversed(list(enumerate(indices))):
				indices[i] += 1
				if indices[i] > 22:
					indices[i] = 0
				else:
					break
		yield indices

def find_next(indices):
	length = len(indices)
	gen = next_passw(indices)
	ret1 = -1
	ret2 = -1
	consecutive = False

	while (ret1 < 0 or ret2 < 0 or not consecutive):
		ret1 = -1
		ret2 = -1
		consecutive = False
		indices = next(gen)
		for i in range(2, length):
			if ret1 < 0 and indices[i] == indices[i - 1] or indices[i - 1] == indices[i - 2]:
				ret1 = indices[i]
			elif ret2 < 0 and indices[i] == indices[i - 1] or indices[i - 1] == indices[i - 2]:
				ret2 = indices[i]
			if indices[i] - 1 == indices[i - 1] and indices[i] - 2 == indices[i - 2]:
				consecutive =  True

with open('input')  as input:
	passw = input.readline()

indices = [alphabet.index(i)  for i in passw.rstrip()]
find_next(indices)
find_next(indices)
passw = ''.join(alphabet[index] for index in indices)
