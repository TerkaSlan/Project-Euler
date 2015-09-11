/*Project Euler solution 12, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

static unsigned check_divisors(unsigned long num){
    unsigned long i;
    unsigned ret = 1;
    for(i=2; i<=num; i++){
        unsigned count = 0;
        while(num%i==0){
            num /= i;
            count++;
        }
        ret*=count+1;
    }
    return ret;
}

int main()
{
    clock_t start, end; float time_passed;
    start = clock();
    unsigned long num=1, i=1;
    while(check_divisors(num)<500){
        num+=++i;
    }
    end = clock();
    time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("%lu\n", num);
    printf("It took me %f seconds\n", time_passed); //0.327864s
    return 0;
}

