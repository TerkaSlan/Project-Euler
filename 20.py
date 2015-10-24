#Project Euler solution 20, author: http://github.com/TerkaSlan #
from time import clock

def factorial():
    fact = 1
    for i in range(2,101,1):
        fact*=i
    return fact

start = clock()
sum = 0
# returns 100!
fact = factorial()

while fact>0:
    sum  += fact%10
    fact /= 10
end = clock()


print 'Found ', sum
print 'It took me ', end-start ,' seconds.' #0.000157s
