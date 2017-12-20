#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024
#define SIZE 10
void menuIDs(char *);

int main(int argc, char **argv) {
  if (argc < 2) return EXIT_FAILURE;

  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    if (line[0] != '\n') {
      char *token = strtok(line, "\n");
      menuIDs(token);
    }
  }  

  return EXIT_SUCCESS;
}

void menuIDs(char *str) {
  int positions[SIZE];
  int i=0;
  char *result = str;

  while (result = strstr(result, "Label ")) {
    int p = result - str;
    positions[i++] = p+5;
    result++; 
  }
  int sum = 0;
  int j;
  for (j=0; j<i; j++) {
    char *copy = strndup(str + positions[j], 10);
    char *token = strtok(copy, "\"}, ");
    sum += atoi(token);
  }
  printf("%i\n", sum);
}
