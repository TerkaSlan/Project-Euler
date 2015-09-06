#Project Euler solution 6, author: http://github.com/TerkaSlan #
from time import clock

def power(base,expo):
    if expo==1: return base
    return base*power(base,expo-1)

start = clock()
sum = 0L
for i in range(1,101,1):
    sum+=power(i,2)
sum = power((100*101/2),2) - sum
end = clock()
print 'Found ', sum
print 'And it took me ', end-start, ' seconds.'
