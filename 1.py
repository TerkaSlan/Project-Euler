#Project Euler solution 1, author: http://github.com/TerkaSlan #
__author__ = 'terka'

from time import clock

start = clock()
sum=0
for i in range(3,1000,3):
    sum += i
for i in range(5,1000,5):
    sum += i
for i in range(15,1000,15):
    sum -= i
end = clock()

print 'Found a solution: ', sum
print 'It took me ', end-start, ' seconds' #0.000106  seconds
