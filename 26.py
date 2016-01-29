#Project Euler solution 26, author: http://github.com/TerkaSlan #
from time import clock

max_length = 0
start = clock()
for i in range(2,1000,1):

	if i % 2 == 0 or i % 5 == 0:
		continue

	length = 0
	multiples_of_ten = 10
	remainder = 0
	while True:
		remainder = multiples_of_ten % i
		length += 1
		if remainder == 1:
			break
		multiples_of_ten *= 10
	
	if length > max_length:
		max_length = length
		max_i = i

end = clock()
print 'Found: ', max_i
print 'Took me ', end - start, ' seconds'
