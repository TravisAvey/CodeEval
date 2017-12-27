#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256
#define SIZE 10

void multiplyLists(char *);
void extractData(char *, char **, char **);
int getValues(char *, int[]);

int main(int argc, char **argv) {
  // return if no file passed
  if (argc < 2) return EXIT_FAILURE;
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold the line
  char line[BUF];
  // get a line form the file
  while (fgets(line, BUF, file)) {
    // if new line, skip
    if (line[0] == '\n') continue;
    // remove newline from each line
    char *token = strtok(line, "\n");
    // call method to multiply lists
    multiplyLists(token);
  }
  return EXIT_SUCCESS;
}

// This method multiplies the lists
//
// Example:
// 9 0 6 | 15 14 9
// we multiply 9 * 15, 0 * 14, 6 * 9
// output:
// 135 0 54
void multiplyLists(char *data) {
  // init data structs to hold the data
  int A[SIZE];
  int B[SIZE];
  char *dataA;
  char *dataB;
  
  // call method to extract data into 2 strings
  extractData(data, &dataA, &dataB);
  // call methods to put the data into
  // arrays, and return how many values
  int i = getValues(dataA, A);
  int j = getValues(dataB, B);

  // loop over the values
  int k;
  for (k=0; k<i; k++)
    // multiply the corresponding values together and output
    printf("%i ", A[k] * B[k]);
  // print new line
  puts("");  
}

// this method extracts the data into two different strings
void extractData(char *data, char **a, char **b) {
  char *token = strtok(data, "|");
  *a = token;
  token = strtok(NULL, "|");
  *b = token;
}

// this method puts the values from the string
// into the array and returns the number of values
int getValues(char *data, int array[]) {
  char *token = strtok(data, " ");
  int i = 0;
  while (token) {
    array[i++] = atoi(token);
    token = strtok(NULL, " ");
  }
  return i;
}
