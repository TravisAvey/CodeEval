#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // buffer size
#define SIZE 20 // array size

// method declarations
void simpleSort(char *);
int extractData(char *, double [SIZE]);
int compare(const void *, const void *);

int main(int argc, char **argv) {
  // open the file passed to program
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // while we can get a line from the file
  while (fgets(line, BUF, file)) {
    // remove the new line from each line
    char *token = strtok(line, "\n");
    // call the simpleSort method
    simpleSort(token);
  }
  return EXIT_SUCCESS;
}

// This method sorts and outputs the input
void simpleSort(char *line) {
  // init an array of doubles
  double nums[SIZE];  
  // call the method to extract the data from the line
  // and gets the number of elements
  int elements = extractData(line, nums);
  // use C's qsort in stdlib.h
  qsort(nums, elements, sizeof(nums[0]), compare);
  // loop over the doubles
  int i;
  for (i=0; i<elements; i++)
    // print out the current number
    // with three decimal places
    printf("%.3f ", nums[i]);
  // output a blank line
  puts("");
}

// this method extracts the data
// places the numbers in the array
// and returns the number of elements
// found in the line
int extractData(char *line, double nums[SIZE]) {
  // init a string to hold the tokens
  char *token;
  // get the token parsed from a space
  token = strtok(line, " ");
  // init a index counter
  int i = 0;
  // while the token is not null
  while (token != NULL) {
    // convert to double, store in current
    // memory location, increment to next
    // memory locatiaon
    nums[i++] = atof(token);
    // get next token
    token = strtok(NULL, " ");
  }
  // return the number of elements
  return i;

}

// this method is used for qsort
// returns 1 if x is greater
// -1 if y i greater
// or 0 if both are the same
int compare(const void *x, const void *y) {
  if (*(double *) x > *(double *) y) return 1;
  else if (*(double *) x < *(double *) y) return -1;
  else return 0; 
}
