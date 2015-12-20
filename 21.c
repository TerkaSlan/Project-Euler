//Project Euler solution 21. author: https://github.com/TerkaSlan

#include <stdio.h>
#include <time.h>

int sum_divisors(unsigned num){
	unsigned i=2, sum=1;
	while(i*i <= num){
		if(num%i == 0){
			sum+=i;
			if(i != num/i)	sum+=num/i;
		}
		i++;
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	clock_t start, end;
	start = clock();
	int res, sum=0;
	for(int i=2; i<10000; i++){
		res = sum_divisors(i);
		if(sum_divisors(res) == i && res != i){	
			printf("\nyes for %d and %i\n", res, i);
			sum += i; 
		}
	}
	end = clock();
	printf("\nSUM: %d", sum);	
	float time_passed = ((end-start)/CLOCKS_PER_SEC)*1.0;
	printf("\nIt took me %f secs to compute", time_passed);
	return 0;
}