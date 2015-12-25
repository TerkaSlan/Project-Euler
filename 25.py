#Project Euler solution 25, author: http://github.com/TerkaSlan #
from time import clock
import math

start = clock()
x = 1L
y = 1l
# 1L just so the while condition with log10() call doesn't fail
result = 1L
counter = 2

while int(math.log10(result))+1 < 1000:
    result = x+y
    x = y
    y = result
    counter += 1

print 'Found ', counter
end = clock()
print 'Took me ', end-start, ' seconds to come up with a solution' # 0.016s