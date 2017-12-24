#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // buffer size for reading file
#define SIZE 10 // max array size for numbers array

void romanNumeral(char *);
void reverseString(char *);

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
    romanNumeral(token);
  }
  return EXIT_SUCCESS;
}

void romanNumeral(char *data) {
    char *romanNumerals[4][SIZE] = {
        { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // ones
        { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // tens
        { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  // hundreds
        { "", "M", "MM", "MMM"} 
    };

    reverseString(data);
    
    int len = strlen(data);
    char answer[128];
    while (len-- > 0) {
        int i = data[len] - '0';
        strcat(answer, romanNumerals[len][i]);
        
    }
    printf("%s\n", answer);
}

void reverseString(char *str) {
    char *p1 = str;
    char *p2 = str + strlen(str) - 1;

    while (p1 < p2) {
        char temp = *p1;
        *p1++ = *p2;
        *p2-- = temp;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // buffer size for reading file
#define SIZE 10 // max array size for numbers array

void romanNumeral(char *);
void reverseString(char *);

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
    romanNumeral(token);
  }
  return EXIT_SUCCESS;
}

// this method prints out the roman numeral
// version of the base-10 digit passed
void romanNumeral(char *data) {
    // init a 2D array to hold the strings of each roman numeral
    char *romanNumerals[4][SIZE] = {
        { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, // ones
        { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, // tens
        { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  // hundreds
        { "", "M", "MM", "MMM"} 
    };

    // reverse the string to start at bigger digit
    reverseString(data);
    // get the len of the string
    int len = strlen(data);
    // init a string to hold the answer
    char answer[128];
    // loop down through the string
    while (len-- > 0) {
        // convert current char to an int
        int i = data[len] - '0';
        // concatenate the roman numeral to the answer string
        strcat(answer, romanNumerals[len][i]);
        
    }
    // output answer
    printf("%s\n", answer);
}

// this method does inplace string reversal
void reverseString(char *str) {
    // init pointer to str
    char *p1 = str;
    // init a pointer to the end of the str
    char *p2 = str + strlen(str) - 1;

    // while p1 is less then p2 location
    while (p1 < p2) {
        // init a temp for current p1 loc
        char temp = *p1;
        // store p2 in p1, then increment p1 loc
        *p1++ = *p2;
        // store temp loc in p2, then decrement p2
        *p2-- = temp;
    }
    // fall off while loop, the str will be reversed
}
