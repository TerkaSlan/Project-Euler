//Project Euler solution 30, author: http://github.com/TerkaSlan
#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#define REASONABLE_LIMIT 1000000

uint64_t fifth_power(uint64_t base){

	uint64_t result = 1;
	for (uint8_t i = 5; i > 0; i--)
		result = result*base;

	return result;
}

int main()
{
	clock_t start, end;
	start = clock();	
	uint64_t dividing_i_to_digits = 0;
	uint64_t sum = 0;
	uint64_t sum_of_all_matches = 0;
	
	for (uint64_t i = 2; i < REASONABLE_LIMIT; i++){

		dividing_i_to_digits = i;
		sum = 0;
		
		while (dividing_i_to_digits > 0){
		
			sum += fifth_power(dividing_i_to_digits % 10);
			dividing_i_to_digits = dividing_i_to_digits / 10;	
		}

		if (i == sum){	
		
			fprintf(stderr,"Found match for: %"PRIu64, i);
			fprintf(stderr,"\n");
			sum_of_all_matches += i;
		}
	}
	end = clock();
	printf("\nFound: %"PRIu64, sum_of_all_matches);
	printf("\nTook me %lf seconds to come up with a solution\n", (end-start)/CLOCKS_PER_SEC*1.0);
	return 0;
}
