alphabet = ['a','b','c','d','e','f','g','h','j','k','m','n','p','q','r','s', 't','u','v','w','x','y','z']
pass_index = []
length = 0

def convert_passw(passw):
	global pass_index
	global alphabet
	global length

	for i in range(0, length):
		pass_index.append(alphabet.index(passw[i]))

def find_next():
	global pass_index
	global length
	ret1 = -1
	ret2 = -1
	consecutive = False



	while (ret1 < 0 or ret2 < 0 or not consecutive):
		ret1 = -1
		ret2 = -1
		consecutive = False
		for i, e in reversed(list(enumerate(pass_index))):
			pass_index[i] += 1
			if pass_index[i] > 22:
				pass_index[i] = 0
			else:
				break
		for i in range(2, length):
			if ret1 < 0 and pass_index[i] == pass_index[i - 1] or pass_index[i - 1] == pass_index[i - 2]:
				ret1 = pass_index[i]
			elif ret2 < 0 and pass_index[i] == pass_index[i - 1] or pass_index[i - 1] == pass_index[i - 2]:
				ret2 = pass_index[i]
			if pass_index[i] - 1 == pass_index[i - 1] and pass_index[i] - 2 == pass_index[i - 2]:
				consecutive =  True



with open('test')  as input:
	passw = input.readline()
length = len(passw) - 1
convert_passw(passw)
find_next()
passw = ''.join(alphabet[index] for index in pass_index)
print(passw)
