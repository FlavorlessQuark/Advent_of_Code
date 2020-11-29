import re

y, x = re.findall(r'\d+', open('input').read())
# y, x = 5,2

amount = sum(range(int(y) + int(x) - 1)) + int(x)
# print(x, y)
val = 20151125

print(amount)
for i in range(amount - 1):
	val *= 252533
	val = val % 33554393
# 	print("Row", pos[0], "Col", pos[1])
print("Val", val)
