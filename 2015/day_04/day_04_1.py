import hashlib as lib

num = 0
result = ""
key = "ckczppom"

def check_hash(key, num):
	md5 = lib.md5()
	key = key + str(num)
	md5.update(key.encode('utf-8'))
	result = md5.hexdigest()
	for i in range (6):
		if result[i] != '0':
			return False
	return True

while (check_hash(key, num) == False):
	num += 1
print("num " + str(num))
