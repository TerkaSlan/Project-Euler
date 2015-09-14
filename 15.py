#Project Euler solution 15, author: http://github.com/TerkaSlan #
from time import clock
import math
start = clock()
p = 1
for i in range(40,20,-1):   p*=i
end = clock()
print p/math.factorial(20)
print 'It took me ', end-start ,' seconds' # 1e-05 seconds
