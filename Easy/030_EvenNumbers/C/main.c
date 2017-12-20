#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

int isEven(char *);

int main(int argc, char **argv) {
  if (argc < 2) return EXIT_FAILURE;
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    printf("%i\n", isEven(token));
  }
  return EXIT_SUCCESS;
}

int isEven(char *data) {
  int num = atoi(data);
  return (num % 2 == 0);

}
