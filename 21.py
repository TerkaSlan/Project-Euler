from time import clock

def sum_divisors(num):
	i=2
	sum=1
	while(i*i <= num):
		if (num%i) == 0:
			sum+=i
			if(i != num/i):
				sum+=num/i
		i+=1
	return sum

start = clock()
total_sum = 0
for i in range(2,10000,1):
	res = sum_divisors(i)
	if(sum_divisors(res) == i and res != i):
		total_sum += i
end = clock()
print 'Found ', total_sum
print 'It took me ', end-start ,' seconds.' # 0.287791s