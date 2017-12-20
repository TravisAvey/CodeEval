#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024  // Buffer size
#define SIZE 25   // Array Size

void swapCase(char *);

int main(int argc, char **argv) {
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string of buffer size
  char line[BUF];
  // while we can get a line from the 
  // file, buffer size at a time
  while(fgets(line, BUF, file)) {
    // strip the new line from each line
    char *token = strtok(line, "\n");
    // call method to swap the case
    swapCase(token);
  }
  return EXIT_SUCCESS;
}

/*
  This method swaps the case of only 
  alpha characters of each line
*/
void swapCase(char *line) {
  // create an array of strings
  char *words[SIZE];
  // init an index
  int i = 0;
  // tokenize the string on spaces
  char *token = strtok(line, " ");
  // while token is not null
  while (token) {
    // put the token into the string array
    words[i++] = token;
    // get the next token from the string
    token = strtok(NULL, " ");
  }
  // declare index counters
  int j;
  int k;
  // loop over each word in the string array
  for (j=0; j<i; j++) {
    // get the length of the current word
    int len = strlen(words[j]);
    // loop over every character in the word
    for (k=0; k<len; k++) {
      // cache the current char
      char c = words[j][k];
      // if lower case letter
      if (c >= 'a' && c <= 'z')
        // sub 32 from char, resulting in upper case
        words[j][k] = c - 32;
      // if upper case
      else if (c >= 'A' && c <= 'Z')
      // add 32, resulting in lower case
        words[j][k] = c + 32;
    }
    // print current word
    printf("%s ", words[j]);
  }
  // output new line
  puts("");
}
