#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define buf 512

void beauString(char *);
int lower(char);

int main(int argc, char **argv) {
  FILE *file = fopen(argv[1], "r");
  char line[buf];
  while(fgets(line, buf, file)) {
    char *token;
    token = strtok(line, "\n");
    beauString(token);   
  } 
  
  return EXIT_SUCCESS;
}

void beauString(char *line) {
  int len = strlen(line);
  char string[len];
  int i;
  int j = 0;
  int count = 0;
  for (i=0; i<len; i++ ) {
    char a = lower(line[i]);
    if (a) {
      string[j++] = a;
      count++;
    }
  }

  for (i=0; i<count; i++)
    printf("%c", string[i]);
  printf("\n");

}

int lower(char ch) {
  if (ch >= 65 && ch <= 90)
    return ch + 32;
  return 0;
}
