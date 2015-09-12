/*Project Euler solution 13, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>

unsigned chain(unsigned num){
    unsigned count=0;
    while(num>1){
        if(num%2==0)    num /= 2;
        else           {num = 3*num +1;}
        count++;
    }

    return count;
}

int main()
{
    clock_t start, end;
    start = clock();
    unsigned i, chain_length, longest=1, starting_num;
    for(i=0; i<1000000; i++){
        chain_length = chain(i);
        if(chain_length>longest)    {longest = chain_length;    starting_num = i;}
    }
    end = clock();
    float time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
    printf("%u", starting_num);
    printf("\nIt took me %f seconds", time_passed); //0.551944 seconds
    return 0;
}

