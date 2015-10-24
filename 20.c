//Project Euler solution 20, author: https://github.com/TerkaSlan
// Included gmp.h library to be able to work with large nums, compile with -lgmp
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <time.h>

int main(void) {
 clock_t start, end;
 float time_passed;
 start = clock();
 mpz_t x;
 mpz_init(x);
 mpz_fac_ui(x,100);
 char *str;	
 unsigned sum = 0;
 //gmp_printf("\n %Zd\n", x);
 str = mpz_get_str(NULL,10,x);
for(int i=0; str[i]; i++){
	sum += str[i]-'0';
}

 /* free used memory */
 mpz_clear(x);
 free(str);

 end = clock();
 printf("\nResult: %u\n", sum);
 time_passed = ((end-start)/CLOCKS_PER_SEC)*1.0;
 printf("It took me %f secs to compute\n", time_passed);
 return 0;
}
