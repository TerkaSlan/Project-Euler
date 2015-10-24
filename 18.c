/*Project Euler solution 18, author: http://github.com/TerkaSlan */
#include <stdio.h>
#include <time.h>
#define N 15

static int findPath(const char triangle[][N], int row, int col){

  int left, right;

  if (row == N) {
    return triangle[row][col];
  }
  left = findPath(triangle, row+1, col);
  right = findPath(triangle, row+1, col+1);

  return triangle[row][col] + (left > right ? left : right);
}



int main(){

  clock_t start, end;
  start = clock();
  char pyramid[N][N] = {
                                      {75},
                                     {95, 64},
                                    {17, 47, 82},
                                  {18, 35, 87, 10},
                                 {20, 4, 82, 47, 65},
                               {19, 1, 23, 75, 3, 34},
                              {88, 2, 77, 73, 7, 63, 67},
                            {99, 65, 4, 28, 6, 16, 70, 92},
                           {41, 41, 26, 56, 83, 40, 80, 70, 33},
                         {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
                        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
                      {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
                     {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27 ,29, 48},
                   {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
                  {4, 62, 98, 27 ,23 ,9 ,70, 98, 73, 93, 38, 53, 60, 4, 23}
  };
  printf("\nThe sum of the longest path is:  %d\n", findPath(pyramid, 0, 0));
  end = clock();
  float time_passed = (end-start)/CLOCKS_PER_SEC;
  printf("It took me %f seconds\n", time_passed);
}

