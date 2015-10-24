//Project Euler solution 19, author: https://github.com/TerkaSlan

#include <stdio.h>
#include <time.h>
int isLeap(unsigned year){
	if(year%400 == 0)	return 1;
	if(year%100 == 0)	return 0;
	if(year%4   == 0)	return 1;
	else		       {return 0;}
}

int main(int argc, char const *argv[])
{
	clock_t start, end;

	int month, days_in_month;
	int sunday = 0;
	int sum = 0;

	start = clock();

	for (int year = 1901; year < 2001; year++)
	{
		month = 1;
		while(month <= 12){
			// Days of the month checking
			if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			days_in_month = 31;
			else{
				if(month == 2 && isLeap(year))
					days_in_month = 29;
				else if(month == 2 && !isLeap(year))
					days_in_month = 28;
				else
					days_in_month = 30;
			}

			while(sunday<days_in_month){
				sunday+=7;
			}

			sunday = sunday%(days_in_month);
			if(sunday == 1)	sum++;
			month++;
		}
	}
	end = clock();
	printf("\n There were %d Sundays on 1st of month in 20th century", sum);
	printf("\nThe solution took me %f seconds\n", ((end-start)/CLOCKS_PER_SEC)*1.0);
	return 0;
}