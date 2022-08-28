total = 0
length = 0

def get_char_data(line):
	global total
	global length
	length += len(line) - 1

	total += len(line) - 1

	length += line.count("\"")
	length += line.count("\\")
	length += 2


with open('input') as input:
	for line in  input:
		get_char_data(line)
total = length - total
print("Solution : ", total)
