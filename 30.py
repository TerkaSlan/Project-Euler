#Project Euler solution 30, author: http://github.com/TerkaSlan #
from time import clock
import math

start = clock()
dividing_i = 0
sum_of_all_matches = 0
sum = 0L
for i in range(2,500000,1):
	sum = 0
	dividing_i = i
	while dividing_i > 0:
		sum += math.pow(dividing_i % 10, 5)	
		dividing_i /= 10
	
	if sum == i:
		sum_of_all_matches += sum

end = clock()
print 'Found: ', sum_of_all_matches
print 'Took me ', end-start, ' seconds to come up with a solution' # 1.9s
		
