#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 256

void compressNumbers(char *);

int main(int argc, char **argv) {
    if (argc < 2) return EXIT_FAILURE;

    FILE *file = fopen(argv[1], "r");

    char line[BUF];
    while (fgets(line, BUF, file)) {
        char *token = strtok(line, "\n");
        compressNumbers(token);
    }

    return EXIT_SUCCESS;
}

void compressNumbers(char *line) {
  
  char *token = strtok(line, " ");
  int current;
  int first = 1;
  int count = 0;
  while (token) {

    if (first) {
      current = atoi(token);
      count++;
      first = 0;

    } else {

      int n = atoi(token);

      if (n != current) {
        printf("%i %i ", count, current);
        current = n;
        count = 1;

      } else {
        count++;
      }
    }
    token = strtok(NULL, " ");
  }
  printf("%i %i\n", count, current);

}
