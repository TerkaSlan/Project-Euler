#Project Euler solution 9, author: http://github.com/TerkaSlan #
from time import clock

def power(base,expo):
    if(expo==1): return base
    return base*power(base,expo-1)

start = clock()
#a,b,c in reverse
for a in range(200,1000,1):
    for b in range(200,1000,1):
        for c in range(200,1000,1): # this will start incrementing
            if(power(a,2)+power(b,2)==power(c,2)):
                if((a+b+c)==1000):
                    end = clock()
                    print 'Found a solution: ', a*b*c
                    print 'It took me ',end-start, ' seconds' # 0.1465s
