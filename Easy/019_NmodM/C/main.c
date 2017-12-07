#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024

int mod(int, int);
int *getInts(char *);

int main(int argc, char **argv) {
  // open the file in read mode
  FILE *file = fopen(argv[1], "r");
  // init a char array of size BUF
  char line[BUF];
  // while fgets can get a line, BUF chunk at a time
  while (fgets(line, BUF, file)) {
    // declare a string
    char *token;
    // remove the newlines
    token = strtok(line, "\n");
    // get an array of integers from the line
    int *nums = getInts(token);
    // output the modulus of n mod m
    printf("%i\n", mod(nums[0], nums[1]));
  }

  return 0;
}

/*
  This method parses a string of two integers
  separated by a comma and returns an array of
  the ints. Example
  2,3
  returns int[2] = {2,3}
*/
int *getInts(char *line) {
  // init an integer array of 2
  int *ints = malloc(sizeof(int) * 2);
  // parse the integers from the line and convert to ints
  char *token;
  token = strtok(line, ",");
  ints[0] = atoi(token);
  token = strtok(NULL, ",");
  ints[1] = atoi(token);
  // return the array
  return ints;
}
/*
  This method performs the modulus operation
  on the 2 ints -- n,m -- without using the
  modulus operator
*/
int mod(int n, int m) {
  // divide n / m
  int div = n / m;
  // get the multiplier of the divisor * m
  int mul = div * m;
  // return the modulus, n minus the multiplier
  return n - mul;
}
