/*Project Euler solution 5, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

unsigned long gcd(unsigned long a, unsigned b){
	unsigned long remainder;
	while(a%b!=0){
		remainder = a%b;		
		a=b;
		b=remainder;
	}

	return b;
}

unsigned long lcm(unsigned long a, unsigned b){
	// lcm of 2 numbers is product / gcd
	return (a*b)/gcd(a,b);
}

int main()
{
	clock_t start, end;
	float time_passed;
	unsigned i;
	unsigned long result=1;
	start = clock();
	//numbers stored in result: 1/1, 2/1, 6/1, 18/3, 36/1,...
	for(i=1; i<=20; i++){
		result = lcm(result,i);
	}	
	end = clock();
	time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
	printf("\nFound answer: %lu", result);
	printf("\nIt took me %f seconds to come up with it\n", time_passed);
	//0.000006 seconds
	return 0;
}
