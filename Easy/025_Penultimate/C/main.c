#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024

void penultimate(char *);

int main(int argc, char **argv) {
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    penultimate(token);
  }
  return EXIT_SUCCESS;
}

void penultimate(char *line) {

  char *words[20];
  int i = 0;
  char *token = strtok(line, " ");
  while (token != NULL) {
    words[i++] = token;
    token = strtok(NULL, " ");
  }
  int last = i - 2;
  printf("%s\n", words[last]);

}
