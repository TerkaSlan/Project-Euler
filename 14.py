#Project Euler solution 14_1, author: http://github.com/TerkaSlan #
from time import clock

def chain(num):
    count=0
    while(num>1):
        if num%2==0:    num/=2
        else:           num = num*3+1
        count+=1
    return count

start = clock()
longest = 0
starting_num=0
for i in xrange(3,1000000,1):
    chain_length = chain(i)

    if(chain_length>longest):   longest=chain_length; starting_num=i
end = clock()

print starting_num
print 'It took me ', end-start, ' seconds' #19.578946s

import time
 
start = time.time()
 
limit = 1000000
collatz_length = [0] * limit
collatz_length[1] = 1
max_length = [1,1]
 
for i in range(1,1000000):
    n,s = i,0
    TO_ADD = [] # collatz_length not yet known
    while n > limit - 1 or collatz_length[n] < 1:
        TO_ADD.append(n)
        if n % 2 == 0: n = n/2
        else: n = 3*n + 1
        s += 1
    # collatz_length now known from previous calculations
    p = collatz_length[n]
    for j in range(s):
        m = TO_ADD[j]
        if m < limit:
            new_length = collatz_length[n] + s - j
            collatz_length[m] = new_length
            if new_length > max_length[1]: max_length = [i,new_length]
 
elapsed = (time.time() - start)
print "found %s at length %s in %s seconds" % (max_length[0],max_length[1],elapsed)
