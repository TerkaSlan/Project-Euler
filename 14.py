#Project Euler solution 14, author: http://github.com/TerkaSlan #
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
