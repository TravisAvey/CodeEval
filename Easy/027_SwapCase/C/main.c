#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024
#define SIZE 25

void swapCase(char *);

int main(int argc, char **argv) {
  FILE *file = fopen(argv[1], "r");

  char line[BUF];

  while(fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    swapCase(token);
  }
  return EXIT_SUCCESS;

}

void swapCase(char *line) {
  char *words[SIZE];
  int i = 0;
  char *token = strtok(line, " ");
  while (token) {
    words[i++] = token;
    token = strtok(NULL, " ");
  }

  int j;
  int k;
  for (j=0; j<i; j++) {
    int len = strlen(words[j]);
    
    for (k=0; k<len; k++) {
      char c = words[j][k];
      if (c >= 'a' && c <= 'z')
        words[j][k] = c - 32;
      else if (c >= 'A' && c <= 'Z')
        words[j][k] = c + 32;
    }
    printf("%s ", words[j]);
  }
  puts("");

}
