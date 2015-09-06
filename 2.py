#Project Euler solution 2, author: http://github.com/TerkaSlan #
__author__ = 'terka'

from time import clock

start = clock()
x=1;y=2; sum=2
while y<4000000:
    x += y
    y += x
    if x%2==0:  sum += x
    if y%2==0:  sum += y

end = clock()

print 'Found a solution: ', sum
print 'It took me ', end-start, ' seconds' #9e-06  seconds
