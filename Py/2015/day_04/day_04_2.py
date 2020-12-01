import hashlib as lib

num = 0
zeroes = 6

def check_hash(key, num):
	md5 = lib.md5()
	key = key + str(num)
	md5.update(key.encode('utf-8'))
	result = md5.hexdigest()

	return result[:zeroes].count("0") == zeroes

key = open("input").read().rstrip()

while (check_hash(key, num) == False):
	num += 1
print("Solution : " + str(num))
