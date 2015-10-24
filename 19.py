#Solution 19, author: http://github.com/TerkaSlan #
from time import clock

def isLeap(year):
    if   year%400 == 0:   return True;
    elif year%100 == 0:   return False;
    elif year%  4 == 0:   return True;
    else:                 return False;

start = clock()
sunday = 0
sum = 0
for year in range(1901,2000,1):
    month = 1
    while month <= 12:
        if month in [1,3,5,7,8,10,12]:
            days_in_month = 31
        else:
            if month==2 and isLeap(year):
                days_in_month = 29
            elif month==2 and not isLeap(year):
                days_in_month = 28
            else:
                days_in_month = 30

        while sunday <days_in_month:
            sunday+=7
        sunday %= days_in_month
        if sunday==1:   sum+=1

        month+=1
end = clock()


print 'Found ', sum
print 'It took me ', end-start ,' seconds.' #0.004493
