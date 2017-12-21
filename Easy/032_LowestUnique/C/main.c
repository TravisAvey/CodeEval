#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512

void lowestUnique(char *);
void extractData(char *, int [], int []);

int main(int argc, char **argv) {

  if (argc < 2) return EXIT_FAILURE;
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    if (line[0] == '\n') continue;
    char *token = strtok(line, "\n");
    lowestUnique(token);
  }
  return EXIT_SUCCESS;
}

void lowestUnique(char *data) {
  // the numbers from the data
  int numbers[20];
  // the count of each number
  // where the index is the number
  // index 1 = count of no. 1
  int count[10];
  int i;
  for (i=0; i<10; i++)
    count[i] = 0;

  extractData(data, count, numbers);
  int j;
  int lowest = -1;
  for (j=9; j>=1; j--) {
    if (count[j] == 1) {
      lowest = j;
    }
  }
  if (lowest == -1)
    printf("0\n");
  else {
    for (j=0; j<i; j++)
      if (numbers[j] == lowest)
        lowest = j+1;
    printf("%i\n", lowest);
  }
}

void extractData(char *data, int count[], int numbers[]) {

  // strip the spaces
  char *token = strtok(data, " ");
  // init an index counter
  int i = 0;
  // while token isn' null
  while (token) {
    // put the number into the array
    numbers[i++] = atoi(token);
    // grab next token
    token = strtok(NULL, " ");
  }

  int j;
  for (j=0; j<i; j++) {
    int index = numbers[j];
    int current = count[index];
    count[index] = ++current;
  }

}
