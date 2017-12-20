#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024
#define SIZE 10
void menuIDs(char *);

int main(int argc, char **argv) {
  // if no file passed, exit
  if (argc < 2) return EXIT_FAILURE;
  // open file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // get each line from the file
  while (fgets(line, BUF, file)) {
    // if not a new line (empty)
    if (line[0] != '\n') {
      // remove new line from the string
      char *token = strtok(line, "\n");
      // call method
      menuIDs(token);
    }
  }  
  return EXIT_SUCCESS;
}

// This method outputs the sum
// of the Label in the JSON input
void menuIDs(char *str) {
  // init an array to hold the
  // poistions of each Label
  int positions[SIZE];
  // init an index for above array
  int i=0;
  // store the JSON in the string result
  char *result = str;
  // while strstr returns something other than NULL
  while (result = strstr(result, "Label ")) {
    // the position is some pointer math
    // the result location minus the string location
    // str is the zeroth location in memory
    // result is the location of Label
    int p = result - str;
    // add 5 to skip over Label and put into positions
    // added 5 so not needing to do strtok twice below
    positions[i++] = p+5;
    // if not increment result address
    // will loop forever
    result++; 
  }
  // init a sum to 0
  int sum = 0;
  // loop over the positions we found
  int j;
  for (j=0; j<i; j++) {
    // make a substring of only 10 chars
    char *copy = strndup(str + positions[j], 10);
    // get the token by striping space " and }
    char *token = strtok(copy, "\"}, ");
    // convert to int and add to sum
    sum += atoi(token);
  }
  // output the sum, will be 0 if no "Label " in the JSON
  printf("%i\n", sum);
}
