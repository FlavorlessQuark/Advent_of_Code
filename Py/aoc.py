import itertools
import re
from collections import Counter, defaultdict


class aoc():
	def get_nums(self,string):
		return [int(x) for x in re.findall(r'\d+', string)]

	def get_input_raw(self, filename="input"):
		self.file = open(filename).read().rstrip()
		self.length = len(self.file)
		self.line_count = self.file.count("\n")

	def get_input_num(self, filename="input"):
		self.get_input_raw(filename)
		self.nums = self.get_nums(self.file)

	def get_input_split(self, filename="input", delim="\n"):
		self.split = self.file.split(delim)

	def __str__(self):
		return "Total len: " + str(self.length) + "Lines: " + str(self.line_count)



#  comprehension [1 if]

