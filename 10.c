/*Project Euler solution 10, author: http://github.com/TerkaSlan */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIMIT 2000000
int main()
{
	clock_t start, end;
	start = clock();
	float time_passed;
	char *sieve = calloc(LIMIT,sizeof(*sieve));
	unsigned i,j;
	long long unsigned sum=1ULL;
	for(i=2; i<LIMIT; i++){
        if(!sieve[i]){
            sum+=i;
            for(j=i*2; j<LIMIT; j+=i){
                sieve[j] = 1;
            }
        }
	}
	end = clock();
    time_passed = 1.0*(end-start)/CLOCKS_PER_SEC;
    printf("Found solution %llu\n", sum);
    printf("It took me %f seconds", time_passed); // 0.039195
    free(sieve);
    return 0;

}

