#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
/*
char *double_to_string(double number, ){
	char *string = malloc();
}*/

int main(int argc, char *argv[])
{
	
	double test = 0.123123123;
	char string[20];
	for (int i = 0; i < 2; i++)
	{	
		double new_test=test*pow(10.0,i);
		new_test/=test;
		printf("%lf\n", new_test);
		test = test - new_test/pow(10.0,i+1);
		printf("%lf\n", test);
	
	}	
	//free(string);
	return 0;
}