#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF 256 // Buffer size
#define SIZE 50 // Array size

void mixedContent(char *);
int getData(char *, char *[]);

int main(int argc, char **argv) {
  // if file not passed, exit
  if (argc < 2) return EXIT_FAILURE;
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // grab each line from file
  while (fgets(line, BUF, file)) {
    // if line is just new line, skip
    if (line[0] == '\n') continue;
    // strip new line
    char *token = strtok(line, "\n");
    // call method to split mixed content
    mixedContent(token);
  }
  return EXIT_SUCCESS;
}

// This method splits the mixed content
// and outputs words separated by commas
// then integers separated by commas
// the words and integers are separated by a pipe
void mixedContent(char *line) {
  // init arrays to hold the data
  char *data[SIZE];
  char *numbers[SIZE];
  char *words[SIZE];
  // boolean values if current line had
  // either a digit or a word
  int hasDigit = 0;
  int hasWords = 0;
  // call method to get the data from the line
  int i = getData(line, data);
  // init counters
  int n = 0, w = 0;
  // loop over the data aray
  int j;
  for (j=0; j<i; j++) {
    // cache the first char of the current word
    char c = data[j][0];
    // if it is a digit
    if (isdigit(c)) {
      // set hasDigit to true
      hasDigit = 1;
      // store this number in array
      numbers[n++] = data[j];
    // else, it is not a digit
    } else {
      // set hasWords to true
      hasWords = 1;
      // store the word in the array
      words[w++] = data[j];
    }
  }
  // if hasWords is true
  if (hasWords) {
    // loop through and output each word
    for (j=0; j<w-1; j++)
      printf("%s,", words[j]);
    printf("%s", words[j]);
  }
  // if hasDigit is true
  if (hasDigit) {
    // and if we had words, then output a pipe symbol
    if (hasWords)
      printf("|");
    // loop through and output each number
    for (j=0; j<n-1; j++)
      printf("%s,", numbers[j]);
    printf("%s", numbers[j]);
  }
  // output newline
  puts("");
}

// This method puts the data in an array
int getData(char *line, char *data[]) {
  // tokenize the line on a comma
  char *token = strtok(line, ",");
  // init a index counter
  int i = 0;
  // while token is not null
  while (token) {
    // store current token
    data[i++] = token;
    // get next token
    token = strtok(NULL, ",");
  }
  // return the index
  return i;
}
