#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024

void findWriter(char *);

int main(int argc, char **argv) {
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // while we can get a line from the file
  while(fgets(line, BUF, file)) {
    // if line is not a new line
    if (line[0] != '\n') {
      // strip the new line from the line
      char *token = strtok(line, "\n");
      // find the writer from the data
      findWriter(token);
    }
  }
  return EXIT_SUCCESS;
}

// this method finds the writer
// from the data and outputs
// the name and birthdate
void findWriter(char *data) {
  // split string on the pipe char
  char *token = strtok(data, "|");
  // store the code
  char *code = token;
  // tokenize string on a space
  token = strtok(NULL, " ");
  // while token is not null
  while (token) {
    // output the corresponding code char
    // from the current token (-1 because 1 based)
    printf("%c", code[atoi(token)-1]);
    // get next token
    token = strtok(NULL, " ");
  }
  // output new line
  puts("");
}
