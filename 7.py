#Project Euler solution 7, author: http://github.com/TerkaSlan #

from time import clock
start = clock()
target = 10001
limit = 200000

primes = dict()
count = 0
for i in range(2, limit+1):
    primes[i] = True
for i in primes:
    if primes[i] == True:
        count+=1
        if count==target:
            end = clock()
            print 'Found ', i
            print 'It took me ', end-start, ' seconds' # 0.182545s
            break
        for f in range(i*2,limit+1, i):
            primes[f] = False


