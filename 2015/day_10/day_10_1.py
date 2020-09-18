num_str =""

with open("input") as input:
	num_str = input.readline()
for i in range(0,50):
	save = num_str[0]
	count = 0
	num = 0
	for n in range(0, len(num_str)):
		if save == num_str[n]:
			count += 1
		else:
			num *= 10
			num += count
			num *= 10
			num += int(save)
			save = num_str[n]
			count = 1
	if str.isdigit(num_str[n]):
		num *= 10
		num += count
		num *= 10
		num += int(save)
		save = num_str[n]
		count = 0
	num_str = str(num)
print(str(len(num_str)))
