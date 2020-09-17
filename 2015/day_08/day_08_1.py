total = 0

def get_char_data(line):
	global total
	length = len(line) - 1
	offset = 0
	total += length

	for index in range(0, len(line) - 2):
		index += offset
		print(line[index] + " " + str(index) + " offset" + str(offset))
		if (index >= len(line) - 2):
			break
		if line[index] == '\\':
			if line[index + 1] == 'x':
				length -= 3
			else:
				length -= 1
			offset += 1
	total -= length - 2

with open('input') as input:
	for line in  input:
		get_char_data(line)

print(total)
#test with \\\
