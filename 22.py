#Project Euler solution 22, author: http://github.com/TerkaSlan #
from time import clock

def countValues(size_of_arr):
    # dictionary of letter evaluations
    values = {'A':1,'B':2,'C':3,'D':4,'E':5,'F':6,'G':7,'H':8,'I':9,'J':10, \
          'K':11,'L':12,'M':13,'N':14,'O':15,'P':16,'Q':17,'R':18,'S':19, \
          'T':20,'U':21,'V':22,'W':23,'X':24,'Y':25,'Z':26}
    i=0; score = 0; name_score = 0
    while i<size_of_arr:
        for j in range (0, names[i].__len__(),1):
            name_score += values[names[i][j]]
        score += name_score*i
        name_score = 0
        i+=1
    return score

start = clock()
fp = open('names.txt', 'r')
names = []
names = sorted(fp.read().replace('"', '').split(','), key=str)
end = clock()
print 'The score is: ', countValues(names.__len__()) 
print 'Took me ', end-start ,' secs to come up with the answer' # 0.007076
