import re

exp = r'(\w+) can fly (\d+) km/s for (\d+) seconds, but then must rest for (\d+) seconds.'

with open('input') as input:
	reindeers = {deer: [int(speed), int(time), int(rest), 0, 0] for line in ipfor deer, speed, time, rest in re.findall(exp, line)}
print reindeers
