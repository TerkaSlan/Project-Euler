/*Project Euler solution 6, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

unsigned power(unsigned base, unsigned expo){
	if(expo==1)	return base;
	return base*power(base,expo-1);
}

int main()
{
    clock_t start, end;
    float time_passed;
    start = clock();
    unsigned i;
    unsigned long long sum=0;
    for(i=1; i<=100; i++){
    	sum+=power(i,2);   
	}
    sum = power((100*101)/2,2)-sum;
	printf("\nFound a solution for %llu", sum);				
	end = clock();
	time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed); // 0.000071s
	return 0;
}
