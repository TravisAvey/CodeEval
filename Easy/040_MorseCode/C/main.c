#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUF 512 // Buffer size
#define SIZE 128 // Size of array


void morseCode(char *);
int doubleSpaces(char *, char *[]);
void output(char *);
char getCode(char *);

int main(int argc, char **argv) {
  // if no file passed, exit
  if (argc < 2) return EXIT_FAILURE;
  
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];

  // get each line from the file
  while (fgets(line, BUF, file)) {
    // strip new lines
    char *token = strtok(line, "\n");
    // call method to change the morse codes to chars
    morseCode(token);
  }
  return EXIT_SUCCESS;
}

// Main entry to the morse code output
void morseCode(char *line) {
  // init an array of strings
  char *codes[20];
  // find the double spaces in the line
  int i = doubleSpaces(line, codes);

  // if there were any double spaces
  if (i > 0) {
    // loop over the number of double spaces
    int j;
    for(j=0; j<i; j++) {
      // output the code
      output(codes[j]);
      // put a space in between the words
      printf(" ");
    }
  // there was not any double spaces
  } else {
    // output the word
    output(line);
  }
  // print a new line
  puts("");
}

// this method outputs the code
void output(char *code) {
  
  // tokenize the string on spaces
  char *token = strtok(code, " ");
  
  // while token is not null
  while (token) {
    // output the the corresponding morse code character
    printf("%c", getCode(token));
    // get the next token
    token = strtok(NULL, " ");
  }
}

// this method finds the locations of double spaces
// creates the substrings and returns the number
// of double spaces in the line
int doubleSpaces(char *line, char *codes[]) {
  // get the length of the line
  int len = strlen(line);
  // init an array of positions of the double spaces
  int pos[10];
  // init a counter
  int j = 0;
  // loop over the line
  int i;
  for(i=0; i<len-1; i++) {
    // get the current char
    char c = line[i];
    // if the char is a space and next is a space
    if (c == ' ' && line[i+1] == ' ') {
      // we found a double space
      pos[j++] = i;
    }
  }
  // init a counter
  int n = 0;
  // if we found any double spaces
  if (j > 0) {
    // init an int to hold the last location
    int last = 0;
    // loop over the number of double spaces
    for (i=0; i<j; i++) {
      // get the current location of a double space
      int loc = pos[i];
      // allocate a new string
      char *to = (char *) malloc(sizeof(char) * loc-last+1);
      // copy substring
      strncpy(to, line + last, loc - last);
      // put the null
      to[loc-last+1] = '\0';
      // update the last location of a double space
      last = loc;
      // save the substring word
      codes[n++] = to;
    }
    // copy last part over
    char *to = (char *) malloc(sizeof(char) * len-last+1);
    strncpy(to, line + last+1, len-last);
    to[len-last+1] = '\0';
    codes[n++] = to;
  }
  return n;
}

char getCode(char *code) {
  if (strcmp(code, ".-") == 0) return 'A';
  else if (strcmp(code, "-...") == 0) return 'B';
  else if (strcmp(code, "-.-.") == 0) return 'C';
  else if (strcmp(code, "-..") == 0) return 'D';
  else if (strcmp(code, ".") == 0) return 'E';
  else if (strcmp(code, "..-.") == 0) return 'F';
  else if (strcmp(code, "--.") == 0) return 'G';
  else if (strcmp(code, "....") == 0) return 'H';
  else if (strcmp(code, "..") == 0) return 'I';
  else if (strcmp(code, ".---") == 0) return 'J';
  else if (strcmp(code, "-.-") == 0) return 'K';
  else if (strcmp(code, ".-..") == 0) return 'L';
  else if (strcmp(code, "--") == 0) return 'M';
  else if (strcmp(code, "-.") == 0) return 'N';
  else if (strcmp(code, "---") == 0) return 'O';
  else if (strcmp(code, ".--.") == 0) return 'P';
  else if (strcmp(code, "--.-") == 0) return 'Q';
  else if (strcmp(code, ".-.") == 0) return 'R';
  else if (strcmp(code, "...") == 0) return 'S';
  else if (strcmp(code, "-") == 0) return 'T';
  else if (strcmp(code, "..-") == 0) return 'U';
  else if (strcmp(code, "...-") == 0) return 'V';
  else if (strcmp(code, ".--") == 0) return 'W';
  else if (strcmp(code, "-..-") == 0) return 'X';
  else if (strcmp(code, "-.--") == 0) return 'Y';
  else if (strcmp(code, "--..") == 0) return 'Z';
  else if (strcmp(code, "-----") == 0) return '0';
  else if (strcmp(code, ".----") == 0) return '1';
  else if (strcmp(code, "..---") == 0) return '2';
  else if (strcmp(code, "...--") == 0) return '3';
  else if (strcmp(code, "....-") == 0) return '4';
  else if (strcmp(code, ".....") == 0) return '5';
  else if (strcmp(code, "-....") == 0) return '6';
  else if (strcmp(code, "--...") == 0) return '7';
  else if (strcmp(code, "---..") == 0) return '8';
  else if (strcmp(code, "----.") == 0) return '9';
}
