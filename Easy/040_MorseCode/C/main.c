#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // Buffer size
#define SIZE 50 // Size of array

// the hash table data type
typedef struct {
  int size;
  char **keys;
  char *values;
} hash_t;

void initHashTable(hash_t *);
void *newHash(int size);
int getIndex(hash_t *, char *);
void insert(hash_t *, char *, char);
char get(hash_t *, char *);
void morseCode(hash_t *, char *);
int doubleSpaces(char *, char *[]);
void output(hash_t *, char *);

int main(int argc, char **argv) {
  // if no file passed, exit
  if (argc < 2) return EXIT_FAILURE;
  
  // open the file
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  
  // init a hash table
  hash_t *h = newHash(SIZE);  
  initHashTable(h);
  
  // get each line from the file
  while (fgets(line, BUF, file)) {
    // strip new lines
    char *token = strtok(line, "\n");
    // call method to change the morse codes to chars
    morseCode(h, token);
  }
  return EXIT_SUCCESS;
}

// Main entry to the morse code output
void morseCode(hash_t *h, char *line) {
  // init an array of strings
  char *codes[10];
  // find the double spaces in the line
  int i = doubleSpaces(line, codes);

  // if there were any double spaces
  if (i > 0) {
    // loop over the number of double spaces
    int j;
    for(j=0; j<i; j++) {
      // output the code
      output(h, codes[j]);
      // put a space in between the words
      printf(" ");
    }
  // there was not any double spaces
  } else {
    // output the word
    output(h, line);
  }
  // print a new line
  puts("");
}

// this method outputs the code
void output(hash_t *h, char *code) {
  
  // tokenize the string on spaces
  char *token = strtok(code, " ");
  
  // while token is not null
  while (token) {
    // output the token
    printf("%c", get(h, token));
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

void initHashTable(hash_t *h) {
  insert(h, ".-", 'A');     insert(h, "-...", 'B');
  insert(h, "-.-.", 'C');   insert(h, "-..", 'D');
  insert(h, ".", 'E');      insert(h, "..-.", 'F');
  insert(h, "--.", 'G');    insert(h, "....", 'H');
  insert(h, "..", 'I');     insert(h, ".---", 'J');
  insert(h, "-.-", 'K');    insert(h, ".-..", 'L');
  insert(h, "--", 'M');     insert(h, "-.", 'N');
  insert(h, "---", 'O');    insert(h, ".--.", 'P');
  insert(h, "--.-", 'Q');   insert(h, ".-.", 'R');
  insert(h, "...", 'S');    insert(h, "-", 'T');
  insert(h, "..-", 'U');    insert(h, "...-", 'V');
  insert(h, ".--", 'W');    insert(h, "-..-", 'X');
  insert(h, "-.--", 'Y');   insert(h, "--..", 'Z');
  insert(h, "-----", '0');  insert(h, ".----", '1');
  insert(h, "..---", '2');  insert(h, "...--", '3');
  insert(h, "....-", '4');  insert(h, ".....", '5');
  insert(h, "-....", '6');  insert(h, "--...", '7');
  insert(h, "---..", '8');  insert(h, "----.", '9');

}

void *newHash(int size) {
  hash_t *h = malloc(sizeof(hash_t));
  h->keys = malloc(sizeof(char *) * size);
  h->values = malloc(sizeof(char) * size);
  h->size = size;
  return h;
}

int getIndex(hash_t *h, char *key) {
  int i = (int) key % h->size;
  while (h->keys[i] && h->keys[i] != key)
    i = (i + 1) % h->size;
  return i;
}


void insert(hash_t *h, char *key, char value) {

  int i = getIndex(h, key);
  h->keys[i] = key;
  h->values[i] = value;
}

char get(hash_t *h, char *key) {
  int i = getIndex(h, key);
  return h->values[i];
}


