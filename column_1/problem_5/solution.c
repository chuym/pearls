/*
 * Problem 5: If 1mb is a hard boundary. How would you solve the problem?
 *
 * usage: ./out small.in
*/
#include <stdio.h>
#include <stdlib.h>
#define LIMIT (4999999 >> 5) + 1 // int array of this size is ~0.59mb

void setAdjusted(int vector[], int v, int lower)
{
  int adjusted = (v - lower) + 1;
  vector[adjusted >> 5] |= 1 << (adjusted & 31); 
}

void printWithOffset(int vector[], int offset)
{
  int number, i, j;

  for(i = 0; i < LIMIT; i++) {
    for(j = 0; j < 32; j ++) {
      number = (i << 5) + j;
      if(exists(vector, number)) {
        printf("%d\n", number + offset + 1);
      }
    }
  }
}

void setValuesInRange(int vector[], FILE * file, int lower, int upper)
{
  char line[7];
  int number;

  while(fgets(line, 1024, file)) {
    number = atoi(line);
    if(number >= lower && number <= upper) {
      setAdjusted(vector, number, lower);
    }
  }

}

int exists(int vector[], int v)
{
  return 1 & vector[v >> 5] >> (v & 31);
}

int main(int argc, const char * argv[])
{
  int i,j;
  int number;
  int vector[LIMIT] = { 0 };

  FILE *file = fopen(argv[1], "r");


  // First we loop the file for numbers between
  // 1000000 - 4999999, then 5000000 - 9999999
  setValuesInRange(vector, file, 1000000, 4999999);
  printWithOffset(vector, 1000000);

  rewind(file);

  setValuesInRange(vector, file, 5000000, 9999999);
  printWithOffset(vector, 5000000);

  return 0;
}
