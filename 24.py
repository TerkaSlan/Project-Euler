#Project Euler solution 24, author: http://github.com/TerkaSlan #
from time import clock
import itertools

start = clock()
permutations = 0
for i in itertools.permutations('0123456789',10):
    permutations += 1
    if permutations == 1000000:
        print 'Found: ', i
        break
end = clock()
print 'Took me ', end-start, ' seconds to come up with a solution' #0.226s