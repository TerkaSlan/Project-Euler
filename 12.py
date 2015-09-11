#Project Euler solution 12, author: http://github.com/TerkaSlan #
from time import clock

def num_divisors(num):
    if num%2==0:  num /= 2
    count=0
    divisors = 1
    while num%2==0:
        num /= 2
        count+=1
    divisors *= (count+1)
    p=3
    while num!=1:
        count = 0
        while num%p == 0:
            count+=1
            num /= p
        divisors *= (count+1)
        p+=2
    return divisors

def return_index(limit):
    n = 1
    num_1, num_2 = num_divisors(n), num_divisors(n+1)
    while num_1*num_2 < limit:
        n += 1
        num_1, num_2 = num_2, num_divisors(n+1)
    return n

start = clock()
index = return_index(500)
triangle = (index * (index + 1)) / 2
end = clock()
print 'Result: ', triangle
print 'SOlution took me ', end-start, ' seconds'
