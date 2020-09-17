total = 0
length = 0

def get_char_data(line):
	global total
	global length
	length += len(line) - 1

	total += len(line) - 1

	for index in range(0, len(line) - 1):
		if line[index] == '"' or line[index] == '\\':
			length += 1
	length += 2


with open('input') as input:
	for line in  input:
		get_char_data(line)
total = length - total
print(total)
#test with \\\
