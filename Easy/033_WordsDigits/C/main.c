#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // buffer size for reading file
#define SIZE 20 // max array size for numbers array

void wordToDigit(char *);

int main(int argc, char **argv) {
  // exit if no file passed
  if (argc < 2) return EXIT_FAILURE;
  // Open the file
  FILE *file = fopen(argv[1], "r");
  // init an array to hold each line
  char line[BUF];
  // get a line from a file until we cant
  while (fgets(line, BUF, file)) {
    // if newline is first char, goto next
    if (line[0] == '\n') continue;
    // strip new line
    char *token = strtok(line, "\n");
    wordToDigit(token);
  }
  return EXIT_SUCCESS;
}

// this method prints out integral number
// of the string passed:
// zero;one;two
// 012
void wordToDigit(char *data) {
    // declare an array of strings
    char *numbers[SIZE];
    // strip out the semi-colons
    char *token = strtok(data, ";");
    int i=0;
    while (token) {
        numbers[i++] = token;
        token = strtok(NULL, ";");
    }

    // for each word in the numbers array
    int j;
    for (j=0; j<i; j++) {
        // check if current word and output corresponding digit
        if (strcmp(numbers[j], "zero") == 0)
            printf("%i", 0);
        else if (strcmp(numbers[j], "one") == 0)
            printf("%i", 1);
        else if (strcmp(numbers[j], "two") == 0)
            printf("%i", 2);
        else if (strcmp(numbers[j], "three") == 0)
            printf("%i", 3);
        else if (strcmp(numbers[j], "four") == 0)
            printf("%i", 4);
        else if (strcmp(numbers[j], "five") == 0)
            printf("%i", 5);
        else if (strcmp(numbers[j], "six") == 0)
            printf("%i", 6);
        else if (strcmp(numbers[j], "seven") == 0)
            printf("%i", 7);
        else if (strcmp(numbers[j], "eight") == 0)
            printf("%i", 8);
        else if (strcmp(numbers[j], "nine") == 0)
            printf("%i", 9);
    }
    // output new line
    puts("");
}