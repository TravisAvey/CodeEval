#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64

int intPow(int, int);
int armstrongNumber(char *, int);

int main(int argc, char **argv) {
  
  FILE *file = fopen(argv[1], "r");
  
  char line[BUF];

  while (fgets(line, BUF, file)) {
  
    char *token;
    token = strtok(line, "\n");
    int len = strlen(token);
    if (armstrongNumber(token, len))
      printf("True\n");
    else
      printf("False\n");
      
  }

  
  return EXIT_SUCCESS;
}

int armstrongNumber(char *line, int len) {
  int sum = 0;
  int i;
  for (i=0; i<len; i++) {
    int n = line[i] - '0';
    sum += intPow(n, len);
  }
  int answer = atoi(line);
  if (sum == answer)
    return 1;
  else
    return 0;
}

int intPow(int base, int exp) {
  int result = 1;
  while (exp) {
    if (exp & 1)
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}
