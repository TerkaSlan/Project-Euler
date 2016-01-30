#Project Euler solution 27, author: http://github.com/TerkaSlan #

from time import clock

def isPrime(expr):
    if expr <= 0:
        return False
    # trying to speed up for most of the non-prime numbers,
    # suprisingly, got 1s out of it
    if expr % 2 == 0 or expr % 3 == 0 or expr % 5 == 0:
        return False

    i = 7;
    while i*i <= expr:
        if expr % i == 0:
            return False
        i += 1

    return True

start = clock()

max_streak = 0
max_product = 0
lower_limit = -999
upper_limit = 1000

for a in range(lower_limit,upper_limit,1):
    # b cannot be negative, it will be immediatelly rejected by isPrime when n = 0
    for b in range(0,upper_limit,1):
        n = 0
        while(isPrime(n*n + a*n + b)):
            n += 1
        #print 'For a=', a, ' b=', b, ' seq found: ', n
        if n > max_streak:
            max_streak = n
            max_product = a*b

end = clock()
print 'Found: ', max_product
print 'Took me ', end-start, 'secs' # 3s
