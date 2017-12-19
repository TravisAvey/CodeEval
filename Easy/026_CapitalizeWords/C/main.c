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

void capitalize(char *line) {
    // create an array of strings
    // store each word in the array
    // go through each word
    // take first char and change to capital letter
    // output the string with all capitalized words
}