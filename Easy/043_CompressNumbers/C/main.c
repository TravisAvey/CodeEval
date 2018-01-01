#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // Buffer size

void compressNumbers(char *);

int main(int argc, char **argv) {
  // if no file, exit  
  if (argc < 2) return EXIT_FAILURE;
  // open file
  FILE *file = fopen(argv[1], "r");
  // create a string
  char line[BUF];
  // get each line, into string
  while (fgets(line, BUF, file)) {
    // strip new lines
    char *token = strtok(line, "\n");
    // call method to compress the sequence
    compressNumbers(token);
  }
  return EXIT_SUCCESS;
}

// This method compresses the sequence
// 
// Example:
// 73 73 73 73 41 41 41 41 41 41 41 41 41 41
// output:
// 4 73 10 41
void compressNumbers(char *line) {
  // tokenize the string on empty spaces
  char *token = strtok(line, " ");
  // declare an int for the current number
  int current;
  // a boolean, init to first run true
  int first = 1;
  // init a count
  int count = 0;
  // while token is not null
  while (token) {
    // if first run
    if (first) {
      // set the current number
      current = atoi(token);
      // increment the count
      count++;
      // set first to false
      first = 0;
    // not first run
    } else {
      // get the number
      int n = atoi(token);
      // if number isnt the same as current
      if (n != current) {
        // output the count/number
        printf("%i %i ", count, current);
        // set the current to this new number
        current = n;
        // reset the count to 1
        count = 1;
      // else number is same as current
      } else {
        // increment count
        count++;
      }
    }
    // get the next token
    token = strtok(NULL, " ");
  }
  // output the final number and count
  printf("%i %i\n", count, current);
}
