#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define buf 512

void beauString(char []);
int compare( const void *a, const void *b);

int main(int argc, char **argv) {
  // open file in read only
  FILE *file = fopen(argv[1], "r");
  // init a string with size of buf
  char line[buf];
  // while we can get a line from the file
  while(fgets(line, buf, file)) {
    // declare a string
    char *token;
    // strip the new lines from the line
    token = strtok(line, "\n");
    // call the method
    beauString(token);   
  } 
  
  return EXIT_SUCCESS;
}

// This method prints out the value
// of the string passed to it.
// Based on the value of each letter
void beauString(char line[]) {
  // get the length of the string
  int len = strlen(line);
  // create a new array
  char string[len];
  // init index holders
  int j=0;
  int i;
  // loop through the string
  for (i=0;i<len;i++) {
    // if the number is alpha
    if (isalpha(line[i])) {
      // convert char to lower case
      string[j++] = tolower(line[i]);
    }
  }
  // declare a counter
  int k;
  // init a new array to hold the number
  // of times a char appears in the array
  int numbers[26];
  // loop through and init each to 0
  for (k=0;k<26;k++) numbers[k] = 0;
  
  // loop through the array
  for (k=0;k<j;k++) {
    // get the current char
    char c = string[k];
    // check if alpha
    if (isalpha(c)) {
      // increment the count of the
      // current char.
      // c - 'a' returns the index of the char
      // then we increment that index location
      numbers[c-'a']++;
    }
  }
  // sort the array
  qsort(numbers, 26, (size_t) sizeof(int), compare);
  // init a sum and counter
  int sum = 0;
  int n = 26;
  // loop over array
  for (i=25; i>=0; i--) {
    // increment the sum, which is
    // the number of times the char occurs
    // by the current number of n
    sum += numbers[i] * n--;
  }
  // output the sum
  printf("%i\n", sum);
}

// used to compare two characters for qsort
int compare (const void *a, const void *b) {
  //return the char values of a - b
  return *(char*) a - *(char*)b;
}
