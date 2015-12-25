//Project Euler solution 23, author: http://github.com/TerkaSlan #
#include <stdio.h>
#include <string.h>
#include <time.h>
#define LIMIT 28123
unsigned sum_of_divisors(unsigned n){
	unsigned sum = 0;
	for(int i=1; i*i<=n; i++){
		if(n%i==0){
			sum+=i;
			// using found divisor i can
			// divide n by it to find the other one
			if(i != n/i && n != n/i)
				sum+=n/i;
		}
	}
	return sum;
}

int main(void)
{
	clock_t start, end;
	start = clock();
	unsigned count=0, num_of_abundants=0, abundant_nums[LIMIT];
	for(int n=1; n<LIMIT+1; n++){
		if(sum_of_divisors(n) > n){
			abundant_nums[num_of_abundants++] = n;
		}
	}

	long unsigned total_sum = 0;
	// by changing value at index i I mark the numbers not to count
	int all_nums[LIMIT];
	memset(all_nums, '\0', LIMIT);

	for(int i=0; i<num_of_abundants; i++){
		count = i;
		while(abundant_nums[i] + abundant_nums[count] < LIMIT){
			all_nums[abundant_nums[i] + abundant_nums[count]] = 1;
			count++;
		}
	}
	for (int j = 0; j < LIMIT; j++)
	{
		if(all_nums[j] != 1)
			total_sum += j;
	}
	end = clock();
	printf("Found: %lu \n", total_sum);
	printf("Took me %f seconds to come up with a solution\n", ((end-start)/CLOCKS_PER_SEC)*1.0); // 0s :D		
	return 0;
}