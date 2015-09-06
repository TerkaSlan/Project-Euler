/*Project Euler solution 9, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

unsigned power(unsigned base, unsigned expo){
	if(expo==1)	return base;
	return base*power(base,expo-1);
}

int main()
{
	int a=1,b=1,c;
	float time_passed;
	clock_t start, end;
	start = clock();
	// Speed increases if I start with reasonable number (200) instead of 0
	for(c=200; c<1000; c++){
		for(b=200; b<c; b++){
            for(a=200; a<b; a++){
                if((power(a,2)+power(b,2))==power(c,2)){
                    if((a+b+c)==1000){
                        end = clock();  time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
                        printf("\nWe have a winner for %d, %d, %d\n", a,b,c);
                        printf("\nThe solution is: %d\n", a*b*c);
                        printf("It took me %f seconds to come up with it\n", time_passed); // 0.04s
                        return 0;
                    }
                }
            }
		}
	}
}

