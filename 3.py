import math
#Project Euler solution 3, author: http://github.com/TerkaSlan #
from time import clock

def is_prime(n):
    if n < 0:
        return False
    for j in range(2, int(math.sqrt(n)+1),1):
        if n%j == 0:
            return False
    return True


limit = 600851475143
i = 1
start = clock()
while i*i <= limit:
    i += 2 #ignoring all even numbers
    if limit % i == 0:
        if is_prime(i):
            max = i
end = clock()
print 'Found: ', max
print 'It took me ', end-start, ' seconds' # 0.096s
