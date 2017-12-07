#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024

int mod(int, int);
int *getInts(char *);

int main(int argc, char **argv) {
  
  FILE *file = fopen(argv[1], "r");
  
  char line[BUF];

  while (fgets(line, BUF, file)) {
    char *token;
    token = strtok(line, "\n");
    int *nums = getInts(token);
    printf("%i\n", mod(nums[0], nums[1]));
  }

  return 0;
}

int *getInts(char *line) {
  int *ints = malloc(sizeof(int) * 2);
  char *token;
  token = strtok(line, ",");
  ints[0] = atoi(token);
  token = strtok(NULL, ",");
  ints[1] = atoi(token);
  return ints;
}

int mod(int n, int m) {
  int div = n / m;
  int mul = div * m;
  return n - mul;

}
