#Project Euler solution 8, author: http://github.com/TerkaSlan #
from time import clock
forbidden = [] # so that i don't take seriously numbers already multiplied

def greatest_adj(input, pos):
    adjacents = []
    max_index = 0
    #THE CORNERS:
    if pos==0:
        adjacents.append(pos+1)
        adjacents.append(pos+51)
        adjacents.append(pos+52)
    elif pos==49:
        adjacents.append(pos-1)
        adjacents.append(pos+51)
        adjacents.append(pos+50)
    elif pos==969:
        adjacents.append(pos+1)
        adjacents.append(pos-51)
        adjacents.append(pos-50)
    elif pos==1018:
        adjacents.append(pos-1)
        adjacents.append(pos-51)
        adjacents.append(pos-52)
    #THE SIDES
    #left side
    elif pos%51==0 and pos!=0:
        adjacents.append(pos-51)
        adjacents.append(pos-50)
        adjacents.append(pos+1)
        adjacents.append(pos+51)
        adjacents.append(pos+52)
    #right side
    elif (pos-49)%51==0:
        adjacents.append(pos-52)
        adjacents.append(pos-51)
        adjacents.append(pos-1)
        adjacents.append(pos+50)
        adjacents.append(pos+51)
    #top
    elif pos>0 and pos<49:
        adjacents.append(pos+51)
        adjacents.append(pos+1)
        adjacents.append(pos+52)
        adjacents.append(pos-1)
        adjacents.append(pos+50)
    #bot
    elif pos>969 and pos<1018:
        adjacents.append(pos-52)
        adjacents.append(pos-51)
        adjacents.append(pos-1)
        adjacents.append(pos-50)
        adjacents.append(pos+1)
    #middle
    else:
        adjacents.append(pos-52)
        adjacents.append(pos-51)
        adjacents.append(pos-1)
        adjacents.append(pos-50)
        adjacents.append(pos+1)
        adjacents.append(pos+51)
        adjacents.append(pos+50)
        adjacents.append(pos+52)
    max_index = adjacents[0]
    for j in adjacents:
        if input[j]>input[max_index] and (not j in forbidden):
            max_index=j
    forbidden.append(pos)
    return max_index

start = clock()
fp = open('8_input.txt', 'r')
input = fp.read(1019) #accounting for \n etc.
input = list(input)
counter = -1
max_index = 1
greatest = 0
product = 9
#Find 9
for i in input:
   counter+=1
   if i=='9':
        max_index = counter
        #Find the greatest adjacent -> repeat
        for j in range(0,12,1):
            max_index = greatest_adj(input,max_index)
            product*=int(input[max_index])
        forbidden=[]
        j=0
        if(greatest<product):
            greatest = product
        product = 9
print greatest # my solution - 1041386274432 || the correct one - 23514624000, took me 0.004047s
end = clock()
print 'The solution took me ', end-start , ' seconds to calculate'
