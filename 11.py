#Project Euler solution 11, author: http://github.com/TerkaSlan #
from time import clock

start = clock()
#convert to list
fp = open('11_input.txt', 'r')
input = fp.read()
# not counting spaces and \n, the list will shink when i remove them later
size = input.__len__()-20*20-1
count=0

input = list(input)
for i in range(0,size,1):
    if not str(input[i]).isalnum():
        char = input[i]
        input.remove(char)
#merging together 2 strings to form 1 int
for i in range(0,size/2+1,1):
    input[i] = int(input[i])*10+int(input[i+1])
    input.remove(str(input[i+1]))

input.pop()
size = input.__len__()
p=1
max=1

# ROW
i=0
while i<size:
    for j in range(0,4,1):
        p *= input[i]
        i+=1
    if p>max:
        max=p
    p=1

# COL
i=0
while i<size:
    for j in range(0,4,1):
        p *= input[i]
        i+=21
    if p>max:
        max=p
    p=1

count=0
#DIAG left-right 1st part
for k in range(0,16,1):
    i=320 - k*20
    while(i<400):
        i -= count*3*21
        for j in range(0,4,1):
            p *= input[i]
            i+=21
        if p>max:
            max=p
        count=1
        p=1
    count=0
#DIAG left-right 2nd part
for k in range(0,16,1):
    i=k+1
    while(i<400):
        i -= count*3*21
        for j in range(0,4,1):
            p *= input[i]
            i+=21
        if p>max:
            max=p
        count=1
        p=1
    count=0

#DIAG right-left 1st part
for k in range(0,16,1):
    i= 3 + k
    while(i<400):
        i -= count*3*21
        for j in range(0,4,1):
            p *= input[i]
            i+=19
        if p>max:
            max=p
        count=1
        p=1
    count=0
#DIAG right-left 2nd part
for k in range(0,15,1):
    i=19 + k*20
    while(i<400):
        i -= count*3*19
        for j in range(0,4,1):
            p *= input[i]
            i+=19
        if p>max:
            max=p
        count=1
        p=1
    count=0

end = clock()
print max
print 'Time taken: ', end-start # 0.006215s
