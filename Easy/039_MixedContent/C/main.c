#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF 256
#define SIZE 50

void mixedContent(char *);

int main(int argc, char **argv) {
  if (argc < 2) return EXIT_FAILURE;
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    if (line[0] == '\n') continue;
    char *token = strtok(line, "\n");
    mixedContent(token);
  }

  return EXIT_SUCCESS;

}


void mixedContent(char *line) {
  char *data[SIZE];
  char *numbers[SIZE];
  char *words[SIZE];

  int hasDigit = 0;
  int hasWords = 0;

  char *token = strtok(line, ",");

  int i = 0;
  while (token) {
    data[i++] = token;
    token = strtok(NULL, ",");
  }
  int n = 0, w = 0;
  int j;
  for (j=0; j<i; j++) {
    char c = data[j][0];
    if (isdigit(c)) {
      hasDigit = 1;
      numbers[n++] = data[j];
    } else {
      hasWords = 1;
      words[w++] = data[j];
    }
  }
  if (hasWords) {
    for (j=0; j<w-1; j++)
      printf("%s,", words[j]);
    printf("%s", words[j]);
  }
  if (hasDigit) {
    if (hasWords)
      printf("|");
    for (j=0; j<n-1; j++)
      printf("%s,", numbers[j]);
    printf("%s", numbers[j]);
  }
  puts("");
}
