#Project Euler solution 10, author: http://github.com/TerkaSlan #
from time import clock
start = clock()
primes = dict()
limit = 2000000
sum = 1
for i in range(0,limit+1,1):
    primes[i] = True

for i in range(2,limit+1,1):
    if(primes[i]==True):
        sum+=i
        for j in range(i*2,limit+1,i):
            primes[j]=False
print sum
end = clock()
print 'It took me ',end-start ,' seconds' # 1.891188ss
