import re

with open("input") as input:
	num_str = input.readline()[:-1]

 #I'm not quite sure I understand what this \2 does, \1 or \3 do not work..
for i in range(0,50):
	exp = re.compile(r'((\d)\2*)')
	num_str = ''.join(str(len(ex[0])) + str(ex[1]) for ex in re.findall(exp, num_str))
print len(num_str)


# \number
# Matches the contents of the group of the same number.
# Groups are numbered starting from 1.
# For example, (.+) \1 matches 'the the' or '55 55', but not 'thethe' (note the space after the group).
# This special sequence can only be used to match one of the first 99 groups. If the first digit of number is 0
# or number is 3 octal digits long, it will not be interpreted as a group match, but as the character with octal value number.
# Inside the '[' and ']' of a character class, all numeric escapes are treated as characters.
