/*
 * Problem 2: How would you implement bit vectors using
 * bitwise operations.
 *
 * This sample implementation can represent numbers from
 * 0 to 32767
 *
 * usage: ./out
*/
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int vector[1024];

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

  set(vector, 24500);
  set(vector, 4);

  printf("Check if 24500 exists in set (should be 1): %d\n", exists(vector, 24500));
  printf("Decimal representation of 24500 (should be 1048576): %d\n", vector[24500 >> 5]);

  printf("Check if 200 exists in set (should be 0): %d\n", exists(vector, 200));

  printf("Check if 4 exists in set (should be 1): %d\n", exists(vector, 4));
  printf("Decimal representation of 4 (should be 8): %d\n", vector[4 >> 5]);

  set(vector, 5);
  printf("Check if 5 exists in set (should be 1): %d\n", exists(vector, 5));
  printf("Decimal representation of bucket containing 4 and 5 (should be 48): %d\n", vector[4 >> 5]);

  printf("4 should still exists (should be 1): %d\n", exists(vector, 4));

  return 0;
}
