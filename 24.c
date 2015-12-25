// Project Euler solution 24, author: http://github.com/TerkaSlan
#include <stdio.h> 
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void swap(int *first, int *second){
	int temp = *first;
	*first   = *second;
	*second   =  temp;
}

void print_array(int *arr, int size){
	assert(size >= 1);
	
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return;
}

int list_permutations(int *nums, int size){
	int count = 1;
	int permutations = 1000000;
	// algorithm is quite difficult to read, try debugging
	// it with fewer iterations to see how it works
	while(count < permutations){
		int i = size -1;
		while(nums[i-1] >= nums[i]){
			i--;
		}
		int j = size;
		while(nums[j-1] <= nums[i-1]){
			j--;
		}
		swap(&nums[i-1], &nums[j-1]);
		i++;
		j = size;
		while(i < j){
			swap(&nums[i-1], &nums[j-1]);
			i++;
			j--;
		}
		count++;
	}
	printf("%d-th sequence:\n", permutations);
	print_array(nums, size);
	return 0;
}

int main(int argc, char *argv[])
{
	clock_t start, end;
	start = clock();
	int numbers[10] = {0,1,2,3,4,5,6,7,8,9};
	list_permutations(numbers, sizeof(numbers)/sizeof(int));
	end = clock();
	printf("Took me %f seconds to come up with a solution\n", ((end-start)/CLOCKS_PER_SEC)*1.0); // 0s
	return 0;
}