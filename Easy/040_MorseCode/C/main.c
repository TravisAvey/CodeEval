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

int main(int argc, char **argv) {
  hash_t *h = newHash(SIZE);  
  initHashTable(h);
  
  return EXIT_SUCCESS;
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


