#Project Euler solution 28, author: http://github.com/TerkaSlan #
'''
Let's look at the 5x5 example:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

There's obviously some kind of relationship between what N is in NxN and the numbers
in diagonals. At first I have 1x1 grid with only 1 (count once even though it belongs to
both of the diagonals). Continuing with odd Ns: 3x3, 5x5, ... until (and including)
1001x1001.
Corner values of NxN will be important, fortunately they are quite easy to compute:
In general terms when having nxn spiral, sum of the 4 corner numbers will be
n^2 + n^2-n+1 + (n^2 -2(n-1)) + (n^2 -3(n-1))

'''

from time import clock

start = clock()
sum = 1L
for i in range (3,1001 + 1, 2):
    sum += (i*i) + (i*i - i + 1) + (i*i - 2*i + 2) + (i*i - 3*i + 3)

end = clock()
print 'Found: ', sum
print 'Took me ', end-start, ' seconds'
