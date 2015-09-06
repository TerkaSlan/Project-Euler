/*Project Euler solution 2, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 4000000
int main()
{
    clock_t start, end;
    float time_passed;
    unsigned x=1,y=2,z, sum=2;
    start = clock();
    while(y<LIMIT){
        x += y;
        y += x;
        if(x%2==0)  sum += x;
        if(y%2==0)  sum += y;
    }
    printf("\nFound a solution %u\n",sum);
    end = clock();
    time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed);//0.000074s
    return 0;
}

