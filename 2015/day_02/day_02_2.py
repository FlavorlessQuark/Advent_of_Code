total = 0

def parse_line(dimensions_str):
	global total
	dimensions = dimensions_str.split('x')
	total += min((2 * int(dimensions[0]) + 2 * int(dimensions[1])), (2 * int(dimensions[1]) + 2 * int(dimensions[2])), (2 * int(dimensions[0]) + 2 * int(dimensions[2])))
	total += int(dimensions[0]) * int(dimensions[1]) * int(dimensions[2])

with open('input') as input:
	for line in input:
		parse_line(line)
print("Total: ", str(total))
