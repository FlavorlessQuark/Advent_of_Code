Trying to find mathematical solution for this:

Approach is as follows - make a function to calculate the distance at any given time t then call this function and awards points for every second

Calculate winner : t = time | v = velocity | d = flying_time | r = rest_time
	- (Cycles completed) * (d * v) + (current distance)

Cycles completed = t /(d + r)
current distance = ???
