/*
 * Problem 3: Implement bitmap sort to solve problem #1
 *
 * usage: ./out small.in
*/
#include <stdio.h>
#include <stdlib.h>
#define LIMIT (9999999 >> 5) + 1


void set(int vector[], int v)
{
  vector[v >> 5] |= 1 << (v & 31); 
}

int exists(int vector[], int v)
{
  return 1 & vector[v >> 5] >> (v & 31);
}

int main(int argc, const char * argv[])
{
  int vector[LIMIT] = { 0 };
  int i,j;
  int number;

  FILE *file = fopen(argv[1], "r");
  char line[7];

  while(fgets(line, 1024, file)) {
    set(vector, atoi(line));
  }

  for(i = 0; i < LIMIT; i++) {
    for(j = 0; j < 32; j ++) {
      number = (i << 5) + j;
      if(exists(vector, number)) {
        printf("%d\n", number);
      }
    }
  }

  return 0;
}
