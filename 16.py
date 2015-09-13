#Project Euler solution 15, author: http://github.com/TerkaSlan #
from time import clock
start = clock()
num = 0L
sum = 0; i=0
digits = pow(2,1000)

while(digits>0):
    sum += digits%10
    digits /= 10
end = clock()
print sum
print 'It took me ', end-start ,' seconds' # 0.000329s
