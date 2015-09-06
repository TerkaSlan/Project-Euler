#Project Euler solution 4, author: http://github.com/TerkaSlan #
from time import clock

def isPalindrome(num):
    backup_num = num;
    reverse=0
    while backup_num>0:
        reverse*=10
        reverse+=backup_num%10
        backup_num/=10
    if reverse==num:    return True
    else:               return False



start = clock()
max=0
for i in range(999,0,-1):
    for j in range(i,0,-1):
        if isPalindrome(j*i):
            if(max<j*i):
                max = j*i
end = clock()
print 'Found ', max
print 'And it took me ', end-start, ' seconds.' # 0.694882  seconds
