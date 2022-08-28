# import re

# def rm_red(st):
# 	index = st.find("red")
# 	l_bound = index
# 	r_bound = index
# 	while (st[l_bound] != "{"):
# 		l_bound -= 1
# 	while (st[r_bound] != "}"):
# 		r_bound += 1
# 	return (l_bound, r_bound + 1)

# lst = open('test', 'r').read()

# while "red" in lst:
# 	bounds = rm_red(lst)
# 	left = lst[:bounds[0]]
# 	right = lst[bounds[1]:]
# 	lst = left + right
# 	print(lst)
# num = [int(x) for x in re.findall(r'-?\d*', lst) if len(x) > 0]
# print(sum(num))

