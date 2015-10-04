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

int main(int argc, const char * argv[])
{
  int vector[LIMIT] = { 0 };
  int i,j;

  FILE *file = fopen(argv[1], "r");
  char line[7];

  while(fgets(line, 1024, file)) {
    set(vector, atoi(line));
  }

  for(i = 0; i < LIMIT; i++) {
    for(j = 0; j < 32; j ++) {
      if((vector[i] >> j) & 1 == 1) {
        printf("%d\n", (i << 5) + j); 
      }
    }
  }

  return 0;
}
