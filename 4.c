/*Project Euler solution 4, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

int isPalindrome(int num){
	int reverse = 0;
	int num_backup = num;
	while(num_backup>0){
		reverse*=10;
		reverse += num_backup%10;
		num_backup/=10;
	}
	if(num==reverse) return 1;
	else	         return 0;
}

int main()
{
	clock_t start, end;
    float time_passed;
    start = clock();

	int i,j, max = 0;	
	for(i=999; i>0; i--){
		for(j=i; j>0; j--){
			// if a palindrome was found
			if(isPalindrome(i*j)){
				if(i*j>max)	max=j*i;
			}	
		}
	}
	printf("\nFound a solution for %d", max);				
	end = clock();
	time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("\nThe execution took me %f seconds\n", time_passed);//0.025972 seconds
	return 0;
}
