#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024  // buffer size

void penultimate(char *);

int main(int argc, char **argv) {
  // open file passed to program
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // while we can get text, BUF size at a time
  while (fgets(line, BUF, file)) {
    // strip the newline
    char *token = strtok(line, "\n");
    // call method to output penultimate word
    penultimate(token);
  }
  return EXIT_SUCCESS;
}

// This method outputs the penultimate word
// from the line (second to last in the line)
void penultimate(char *line) {
  // declare an array of strings
  char *words[20];
  // init an index counter to 0
  int i = 0;
  // get the token, on a space
  char *token = strtok(line, " ");
  // while the token is not null
  while (token != NULL) {
    // put current token into the words array
    // and increment counter to next address
    words[i++] = token;
    // get next token
    token = strtok(NULL, " ");
  }
  // get the 2nd to last word
  // NOTE: if the line has only 1 word
  // this will throw a segmentation fault
  // because we will be out of range in the
  // array
  int last = i - 2;
  // output the 2nd to last word
  printf("%s\n", words[last]);

}
