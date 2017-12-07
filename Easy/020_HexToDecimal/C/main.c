#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF 256

int main(int argc, char **argv) {
  // open the file passed to program
  FILE *file = fopen(argv[1], "r");
  // declare an array to hold the line
  char line[BUF];
  // while we can get a line from the file
  while (fgets(line, BUF, file)) {
    // remove the new line from each line
    char *token;
    token = strtok(line, "\n");
    // ouptut the integer form of the hexadecimal
    printf("%i\n", (int)strtol(token, NULL, 16));
    
  }

  return EXIT_SUCCESS;
}
