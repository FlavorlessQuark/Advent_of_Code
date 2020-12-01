import re

exp = r'(\w+).*(\d+).*(\d+).*(\d+).*'


with open('test') as input:
	reindeers = {deer:[int(speed), int(time), int(rest), 0, 0, 0] for line in input for deer, speed, time, rest in re.findall(exp, line)}

for _ in range(2503):
	lead = 0
	for deer in reindeers:
		if reindeers[deer][3] != reindeers[deer][1]:
			reindeers[deer][3] += 1
			reindeers[deer][4] += reindeers[deer][0]
print(reindeers)
