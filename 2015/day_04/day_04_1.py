import hashlib as lib

num = 0
key = ""
result = ""
line = "ckczppom"

def check_hash(key, num):
	md5 = lib.md5()
	key = key + str(num)
	md5.update(key.encode('utf-8'))
	result = md5.hexdigest()
	#print("key " + key + "res "+ result)
	for i in range (6):
		if result[i] != '0':
			return False
	return True

#with open('input') as input:
#	line = input.read().splitlines()
key = key + line
while (check_hash(key, num) == False):
	num += 1
	print(str(num))
print("num " + str(num))
