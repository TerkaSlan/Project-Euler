// Project Euler solution 25, author: https://github.com/TerkaSlan
// compile with -lgmp flag
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gmp.h>

int main(int argc, char *argv[])
{
	clock_t start, end;
	start = clock();
	// defining and setting up the mpz variables
	// for more info on functions under gmp.h lib go to: https://gmplib.org/manual/index.html#Top
	mpz_t x,y,result;
	mpz_init(x);
	mpz_set_ui(x,1);
	mpz_init(y);
	mpz_set_ui(y,1);
	mpz_init(result);
	mpz_set_ui(result,0);
	
	char *str = "0";
	unsigned short counter = 2;
	
	while(strlen(str) < 1000){
		mpz_set(result, x);
		mpz_add(result, result, y);
		mpz_set(x,y);
		mpz_set(y,result);
		counter++;
		// must transform mpz number into a string
		str = mpz_get_str(NULL,10,result);
	}

	mpz_clear(x);
	mpz_clear(y);
	mpz_clear(result);
	printf("Found: %d\n", counter);
	free(str);
	end = clock();
	printf("Took me %f secs to some up with a solution\n", ((end-start)/CLOCKS_PER_SEC)*1.0); // 0s
}