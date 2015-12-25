#Project Euler solution 23, author: http://github.com/TerkaSlan #
from time import clock
import math

def is_abundant(num):
    if num < 12:
        return False
    sum = 1
    for x in range(2,(int)(math.sqrt(num))+1):
        if num%x == 0:
            sum += x + num/x
    # correct is the sum is a perfect square
    if math.sqrt(num) == (int)(math.sqrt(num)):
        sum -= math.sqrt(num)
    return sum>num

start = clock()
abundants = list(i for i in range(1,28123) if is_abundant(i))

total_sum = 0
is_rewritable_as_sum = False

# guarantees there are no duplicated in abundants
abundants = set(abundants)
# according to wolphram mathematica: Every num > 20161 can be expressed as sum of 2 abundants
for i in range(1,20161+1,1):
    # any() returns true if at least 1 element is in abundants
    if not any( (i-abundant in abundants) for abundant in abundants):
        total_sum += i

end = clock()
print total_sum
print 'Took me ', end-start, ' seconds to come up with a solution' # 2.103s