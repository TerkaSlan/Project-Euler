#Project Euler solution 5, author: http://github.com/TerkaSlan #
from time import clock

def gcd(a,b):
    while a%b!=0:
        remainder = a%b
        a=b
        b=remainder
    return b

def lcm(a,b):
    return (a*b)/gcd(a,b)

start = clock()
result = 1
for i in range(1,21,1):
    result = lcm(result,i)
end = clock()
print 'Found ', result
print 'And it took me ', end-start, ' seconds.' #1.9e-05  seconds
