/*
 * Problem 1: If memory were not scarce, how would you implement
 * a sort in a language with libraries for representing and sorting
 * sets
 *
 * usage: ./out small.in
*/
#include <stdio.h>
#include <stdlib.h>
#define LIMIT 1000 // Limit of the input.

int compare(const void * left, const void * right)
{
  if( *(long*)left < *(long*)right ){
    return -1;
  } else if( *(long*)left > *(long*)right ) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, const char * argv[])
{
  FILE *file = fopen(argv[1], "r");
  char line[7];
  long numbers[LIMIT];
  long i = 0;

  while(fgets(line, 1024, file)) {
    numbers[i] = strtol(line, NULL, 10);
    i++;
  }

  qsort(numbers, LIMIT, sizeof(long), compare);

  for(i = 0; i < LIMIT; i++) {
    printf("%d\n", numbers[i]);
  }

  return 0;
}

