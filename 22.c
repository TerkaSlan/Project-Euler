// Project Euler 22, author: https://github.com/eagletmt/project-euler-c
// I just added the time watching functionality and learned from this beautiful piece :)
/*
 * Copyright (c) 2009, eagletmt
 * Released under the MIT License <http://opensource.org/licenses/mit-license.php>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

static int compare(const void *x, const void *y);

int main(void)
{
  int count = 0;
  FILE *fp;
  char path[] = "names.txt";
  char **names;
  int i;
  int sum = 0;

  clock_t start, end;
  start = clock();

  fp = fopen(path, "r");
  if (!fp) {
    perror(path);
    return 1;
  }

  // 2D malloced array
  names = malloc(8169 * sizeof *names);
  names[count] = malloc(16);
  while (1) {
    fscanf(fp, "\"%[^\"]\",", names[count]);            
    //when the read string was empty
    if(names[count][0] == '\0')
      break;
    names[++count] = malloc(16);
  }
  free(names[count]);
  fclose(fp);

  qsort(names, count, sizeof *names, compare);

  for (i = 0; i < count; i++) {
    int j, s = 0;
    for (j = 0; names[i][j] != 0; j++) {
      s += names[i][j]-'A'+1;
    }
    sum += s * (i+1);

    free(names[i]);
  }
  free(names);

  printf("%d\n", sum);

  end = clock();
  float time_passed = (end-start)*1.0/CLOCKS_PER_SEC;
  printf("\nIt took me: %f seconds.", time_passed); // 0.008291s

  return 0;
}

int compare(const void *x, const void *y)
{
  return strcmp(*(char * const *)x, *(char * const *)y);
}

