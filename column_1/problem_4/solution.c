/*
 * Problem 4: How can you generate k numbers between
 * 0 and n-1 in random order?
 *
 * Usage: ./out k n > file
 */
#include <stdio.h>
#include <stdlib.h>

int rand_lim(int limit) {
  int divisor = RAND_MAX/(limit+1);
  int retval;

  do { 
    retval = rand() / divisor;
  } while (retval > limit);

  return retval;
}

int main(int argc, const char * argv[])
{
  srand(time(NULL));

  int k = atoi(argv[1]);
  int n = atoi(argv[2]);
  int i;

  for(i = 0; i < n; i++) {
    printf("%d\n", rand_lim(k));
  }

  return 0;
}
