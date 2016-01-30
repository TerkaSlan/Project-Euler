//Project Euler solution 27, author: http://github.com/TerkaSlan
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <inttypes.h>

bool isPrime(int32_t expression)
{
  if (expression <= 0)
    return false;

  for(uint32_t i = 2; i*i <= expression; i++){
    if(expression % i == 0){
      return false;
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  clock_t start = clock();
  int16_t const lower_limit = -1000;
  int16_t const upper_limit = 1000;

  uint32_t max_count = 0;
  int32_t product_of_the_coef = 0;
  int32_t n = 0;

  for (int32_t a = lower_limit + 1; a < upper_limit; a++) {
    for (int32_t b = lower_limit + 1; b < upper_limit; b++) {
      for(n = 0; isPrime(n*n + a*n + b); n++);
      if(n > max_count){
        max_count = n;
        product_of_the_coef = a*b;
      }
    }
  }
  clock_t end = clock();
  printf("Product: %" PRId32, product_of_the_coef);
  printf("\nTook me %f secs\n", ((end-start)/CLOCKS_PER_SEC)*1.0);
  return 0;
}
