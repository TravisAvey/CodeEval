#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 50

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
  if (argc < 2) return EXIT_FAILURE;
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  hash_t *h = newHash(SIZE);  
  initHashTable(h);
  while (fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    morseCode(h, token);

  }
  
  return EXIT_SUCCESS;
}

void morseCode(hash_t *h, char *line) {
  char *codes[10];
  int i = doubleSpaces(line, codes);

  if (i > 0) {
    int j;
    for(j=0; j<i; j++) {
      output(h, codes[j]);
      printf(" ");
    }
  
  } else {
    output(h, line);
  }
  puts("");

}

void output(hash_t *h, char *code) {
  printf("*code = %s\n", code);
  char *token = strtok(code, " ");
  printf("*token = %s\n", token);
  while (token) {
    printf("%c", get(h, token));
    token = strtok(NULL, " ");
  }
}

int doubleSpaces(char *line, char *codes[]) {
  int len = strlen(line);
  int pos[10];
  int j = 0;
  int i;
  for(i=0; i<len-1; i++) {
    char c = line[i];
    if (c == ' ' && line[i+1] == ' ') {
      pos[j++] = i;
    }
  }
  int n = 0;
  if (j>0) {
    int last = 0;
    
    for (i=0; i<j; i++) {
      int loc = pos[i];
      char *to = (char *) malloc(sizeof(char) * loc-last+1);
      strncpy(to, line + last, loc - last);
      to[loc-last+1] = '\0';
      last = loc;
      codes[n++] = to;
    }
    // copy last part over
    char *to = (char *) malloc(sizeof(char) * len-last+1);
    strncpy(to, line + last, len-last);
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


