#Project Euler solution 14_2, author: http://github.com/TerkaSlan #
#Used chain_length list for caching, imporved time by 18 seconds !#
from time import clock

chain_length = [0]*1000000

def chain(num):
    count=0
    while(num>1):
        if(num<1000000):
            # look for sequence asossiated with num
            if(chain_length[num]!=0):
                count+= chain_length[num]
                return count
        if num%2==0:    num/=2
        else:           num = num*3+1
        count+=1
    return count

start = clock()
longest = 0
starting_num=0
for i in xrange(3,1000000,1):
    chain_length[i] = chain(i)

    if(chain_length[i]>longest):   longest=chain_length[i]; starting_num=i
end = clock()

print starting_num
print 'It took me ', end-start, ' seconds' #1.574s

