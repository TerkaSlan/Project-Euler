/*Project Euler solution 3, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

int main()
{
    clock_t start, end;
    float time_passed;
    start = clock();
    unsigned long long i, num = 600851475143ULL;

    for(i=2ULL; i<num; i++){
        // Found the divisor, divide num until not divisible anymore
        while(num % i == 0){
            num /= i;
        }
	
    }

    printf("Found: %llu", num);

    end = clock();
    time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed); // 0.000317s
    return 0;
}

