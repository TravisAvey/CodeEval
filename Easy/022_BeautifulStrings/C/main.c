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

  qsort(string, (size_t)j, (size_t) sizeof(char), compare);

  int k;
  int numbers[26];
  for (k=0;k<26;k++) numbers[k] = 0;

  for (k=0;k<j;k++) {
    char c = string[k];
    if (isalpha(c)) {
      int n = numbers[c-'a'];
      printf("[%c-'a'] = %i \n", c, n);
      n++;
      numbers[c-'a'] = n;
    }
  }

  int sum = 0;
  int n = 26;
  for (i=25; i>=0; i--) {
    sum += numbers[i] * n--;
  }
  printf("%i\n", sum);

}

int compare (const void *a, const void *b) {
  // int iA = * ( (int *) a);
  // int iB = * ( (int *) b);
  // if (iA == iB) return 0;
  // else if (iA < iB) return -1;
  // else return 1;
  return *(char*) a - *(char*)b;
}
