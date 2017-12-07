#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 128

int intPow(int, int);
int armstrongNumber(char *, int);

int main(int argc, char **argv) {
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // while we can get a line from the file
  while (fgets(line, BUF, file)) {
    // strip the newlines
    char *token;
    token = strtok(line, "\n");
    // get the length
    int len = strlen(token);
    // if armstrong number output True
    if (armstrongNumber(token, len))
      printf("True\n");
    // else output False
    else
      printf("False\n");
      
  }
  return EXIT_SUCCESS;
}

/*
  This method determines if the number is an
  armstrong number or not
  Example:
  153 
  where the sum is the power of each digit by length of
  the number
  where in 153, the length is 3
  1^3 = 1 + 5^3 = 125 + 3 ^ 3 = 27 => 1 + 125 + 27 = 153
*/
int armstrongNumber(char *line, int len) {
  // init a sum
  int sum = 0;
  int i;
  // loop over every number in the string
  for (i=0; i<len; i++) {
    // conver the current char to an int
    int n = line[i] - '0';
    // add the power of n^len to the sum
    sum += intPow(n, len);
  }
  // convert the string to an int
  int answer = atoi(line);
  // if the sum is the same as the answer
  if (sum == answer)
    // return true(1)
    return 1;
  else
    // else return false (0)
    return 0;
}

/*
  This method conducts the mathematical
  power operation on the base and exponent
  and returns an int
*/
int intPow(int base, int exp) {
  // init the result to 1
  int result = 1;
  // while exponent is not 0
  while (exp) {
    // if exponent AND 0001 is not 0
    if (exp & 1)
      // multiply result * base and store back into result
      result *= base;
    // shift the bits of the exponent to the right
    exp >>= 1;
    // multiply the base by itselft
    base *= base;
  }
  // return base ^ exp
  return result;
}
