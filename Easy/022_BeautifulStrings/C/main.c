#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define buf 512

void beauString(char []);
int compare( const void *a, const void *b);

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

void beauString(char line[]) {
  int len = strlen(line);
  char string[len];
  int j=0;
  int i;
  for (i=0;i<len;i++) {
    if (isalpha(line[i])) {
      string[j++] = tolower(line[i]);
    }
  }
  
  int sum = 0;
  int n = 26;
  for (i=j-1; i>=0; i--)
    sum += string[i]*n--;
  printf("%i\n", sum);

}

int compare (const void *a, const void *b) {
  int iA = * ( (int *) a);
  int iB = * ( (int *) b);
  if (iA == iB) return 0;
  else if (iA < iB) return -1;
  else return 1;

}
