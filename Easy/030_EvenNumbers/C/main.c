#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256 // buffer for reading file

int isEven(char *);

int main(int argc, char **argv) {
  // if arg count is less than 2, exit
  if (argc < 2) return EXIT_FAILURE;
  // open file
  FILE *file = fopen(argv[1], "r");
  // string for each line
  char line[BUF];
  // while we can get a line from file
  while (fgets(line, BUF, file)) {
    // strip \n
    char *token = strtok(line, "\n");
    // output if even or not
    printf("%i\n", isEven(token));
  }
  return EXIT_SUCCESS;
}

// this method returns 0 odd
// 1 if even
int isEven(char *data) {
  int num = atoi(data);
  return (num % 2 == 0);
}
