#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512   // Buffer
#define SIZE 256  // array size

void capitalize(char *);

int main(int argc, char **argv) {
  // open the file passed from argv[1]
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // while we can get a line from the file
  while(fgets(line, BUF, file)) {
    // strip the newline
    char *token = strtok(line, "\n");
    capitalize(token);
  }
  return EXIT_SUCCESS;
}

// this method capitalizes the first
// character of each word
void capitalize(char *line) {
    // create an array of strings
    char *words[SIZE];
    // store each word in the array
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
      
      words[i++] = token;
      token = strtok(NULL, " ");
    }
    // go through each word
    int j;
    for (j=0; j<i; j++) {
      // save the first character of the word
      char c = words[j][0];
      // if is alpha, and lowercase
      if (c >= 'a' && c <= 'z')
        // subtract 32, converting to uppercase
        // store uppercase back into word
        words[j][0] = c - 32;
      // output the word
      printf("%s ", words[j]);    
    }
    // output a new line
    puts("");
}
