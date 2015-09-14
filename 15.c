/*Project Euler solution 15, author: http://github.com/TerkaSlan */

/* This one wasn't really a programming as much as mathematical challenge, the key here was to realize that for n*n grid
   you can only go n*right and n*down in different order, so what we're looking for is nth class permutations of n elements.
   Code in C is a bit more challenging since I can't compute the factorial straightforwardly (overflow), but that can
   be easily taken care of.*/
#include <stdio.h>
#include <time.h>
int main()
{
    clock_t start, end;
    start = clock();
    int i,divisors[19];
    for(i=0; i<19; i++) {divisors[i]=i+2;}
    short unsigned multiply = 40;
    unsigned long long p=1;
    while(multiply>20){
        p*=multiply;
        //to avoid ULL overflow, i'm immediately dividing by factors in 20!
        for(i=0; i<19; i++){
            if(divisors[i]!=0){
                if(p%divisors[i] == 0){
                    p/=(i+2);
                    divisors[i] = 0;
                }
            }
        }
        multiply--;
    }
    end = clock();
    printf("%llu\n", p);
    printf("\nIt took me: %f seconds", (end-start)*1.0/CLOCKS_PER_SEC); // 0.000005 seconds
    return 0;

}

