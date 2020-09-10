total = 0

def parse_line(dimensions_str):
	global total
	dimensions = dimensions_str.split('x')
	total += 2 * int(dimensions[0]) * int(dimensions[1])
	total += 2 * int(dimensions[0]) * int(dimensions[2])
	total += 2 * int(dimensions[1]) * int(dimensions[2])
	total += min((int(dimensions[0]) * int(dimensions[1])), (int(dimensions[1]) * int(dimensions[2])), (int(dimensions[0]) * int(dimensions[2])))

with open('input') as input:
	for line in input:
		parse_line(line)
print("Total: ", str(total))
