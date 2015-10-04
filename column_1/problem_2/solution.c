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
  return vector[v >> 5] >> v & 31;
}

int main(int argc, const char * argv[])
{

  int test_a = 24500;
  int test_b = 4;

  set(vector, test_a);
  set(vector, test_b);

  printf("Check if 24500 exists in set (should be 1): %d\n", exists(vector, 24500));
  printf("Check if 200 exists in set (should be 0): %d\n", exists(vector, 200));
  printf("Check if 4 exists in set (should be 1): %d\n", exists(vector, 4));
  printf("Check if 4124 exists in set (should be 0): %d\n", exists(vector, 4124));

  return 0;
}
