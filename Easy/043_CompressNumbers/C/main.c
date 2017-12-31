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
  int current = atoi(token);
  int count = 0;
  while (token) {
    int n = atoi(token);
    if (n != current) {
      printf("%i %i ", count, current);
      current = n;
      count = 1;
    } else {
      count++;
    }
    token = strtok(NULL, " ");
  }
  puts("");

}
