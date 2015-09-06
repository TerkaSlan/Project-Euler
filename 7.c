/*Project Euler solution 7, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    float time_passed;

    unsigned n=1000000, i,j,*sieve, count=0;
    const int target = 10001;
    start = clock();
    sieve = calloc(n,sizeof(*sieve));

    for(i=2; i<n; i++){
        // do this if sieve[i]==0. At the beg. everything is set to 0,
        if(!sieve[i]){
            count++;
            if(count==target){
                printf("\nI stopped at %d\n", i);
                break;
            }

            for(j=2*i; j<n; j+=i){ //...then multiples of primes are ruled out
                sieve[j]=1;
            }
        }
    }
    free(sieve);
    end = clock();
    time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed); //0.035446 seconds
    return 0;
}

