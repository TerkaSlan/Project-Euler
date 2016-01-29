//Project Euler solution 26, author: http://github.com/TerkaSlan #
#include <stdio.h>
#include <inttypes.h>
#include <gmp.h> // compile w/ -lgmp
#include <time.h>

uint32_t find_length_of_seq(uint16_t i)
{
  mpz_t multiples_of_tens;
  mpz_t remainder;
  mpz_init(multiples_of_tens);
  mpz_init(remainder);
  mpz_set_ui(multiples_of_tens,10);
  mpz_set_ui(remainder,0);
  uint32_t length_of_sequence = 0;

  // loop mods multiples of 10 with i until the sequence ends (when 10^n%i == 1)
  while (1){
    mpz_mod_ui(remainder,multiples_of_tens,i);
    length_of_sequence++;
    if (mpz_cmp_ui(remainder,1) == 0){
      break;
    }
    mpz_mul_ui(multiples_of_tens, multiples_of_tens,10);
  }

  mpz_clear(multiples_of_tens);
  mpz_clear(remainder);
  return length_of_sequence;
}


int main(int argc, char const *argv[]) {

  uint32_t length = 0;
  uint32_t max_length = 0;
  uint32_t max_i = 0;
  const uint32_t upper_limit = 1000;

  clock_t start, end;
  start = clock();
  for (uint16_t i = 3; i < upper_limit; i++){

    if (i % 2 == 0 || i % 5 == 0) // i div. by 2 or 5 will not produce any sequence
      continue;
    else{
      length = find_length_of_seq(i);
    }
    if(length > max_length){
      max_i = i;
      max_length = length;
    }
  }

  printf("The longest seq found for: %" PRIu32, max_i);
  printf("\nTook me: %f seconds\n", ((end-start)/CLOCKS_PER_SEC)*1.0);
  return 0;
}
