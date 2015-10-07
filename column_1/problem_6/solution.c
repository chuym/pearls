/*
 * Problem 6: How would you implement it if a number could appear
 * at most 10 times.
 *
 * For simplicity purposes, memory is not a limit.
 *
 * usage: ./out small.in
 */

#include <stdio.h>
#include <stdlib.h>
#define LIMIT (9999999 >> 3) + 1 // Each number is represented in 4 bits.

int vector[LIMIT] = { 0 };

void set(int vector[], int v)
{
  int i = v >> 3;
  int current = (vector[i] >> (v & 3)) & 0x0F;

  if(current <= 10) {
    current = current + 1;
    vector[i] &= current & 0xFFFFFFFF;
  }
}

int exists(int vector[], int v)
{
  return (vector[v >> 3] >> (v & 3)) & 0x0F >= 1;
}

void print(int vector[], int v)
{
  int times = vector[v >> 3] & 0x0F;
  int i;
  for(i = 0; i < times; i++) {
    printf("%d\n", v);
  }
}

void dump(int vector[])
{
  int i,j;
  int number;

  for(i = 0; i < LIMIT; i++) {
    for(j = 0; j < 4; j++) {
      number = (i << 3) + j;
      if(exists(vector, number)) {
        print(vector, number);
      }
    }
  }
}

int main(int argc, const char * argv[])
{
  FILE *file = fopen(argv[1], "r");
  char line[7];

  while(fgets(line, 1024, file)) {
    set(vector, atoi(line));
  }

  dump(vector);
}
