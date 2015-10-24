#Project Euler solution 18, author: http://github.com/TerkaSlan #
from time import clock

def findMaxPath(row, rowNum):

    for i in range(len(row[rowNum])):
        row[rowNum][i] += max([row[rowNum+1][i], row[rowNum+1][i+1]])

    if len(row[rowNum])==1: return row[rowNum][0]
    else:                   return findMaxPath(row,rowNum-1)

start = clock()
row = []
with open('18_input.txt') as fd:
    for line in fd:
        row.append([int(i) for i in line.rstrip('\n').split(" ")])

sum = findMaxPath(row, len(row)-2)
end = clock()


print 'Found ', sum
print 'It took me ', end-start ,' seconds.' # 0.000437  seconds