#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512


int main(int argc, char **argv) {
  

  FILE *file = fopen(argv[1], "r");

  char line[BUF];

  while(fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    printf("%s\n", token);
  }

  return EXIT_SUCCESS;
}
