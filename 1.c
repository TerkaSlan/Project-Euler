/*Project Euler solution 1, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 1000
int main()
{
    clock_t start, end;
    float time_passed;

    short unsigned i;
    unsigned sum=0;
    start = clock();
    for(i=3; i<LIMIT; i+=3){
        sum += i;
    }
    for(i=5; i<LIMIT; i+=5){
        sum += i;
    }
    //Subtracting multiples of 15, since they were counted twice
    for(i=15; i<LIMIT; i+=15){
        sum -=i;
    }
    end = clock();

    printf("\nI found a solution: %u\n", sum);

    time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed); // 0.000007 seconds
    return 0;
}

