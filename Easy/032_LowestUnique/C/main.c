#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512

void lowestUnique(char *);
int extractData(char *, int [], int []);

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
    // get the lowest unique
    lowestUnique(token);
  }
  return EXIT_SUCCESS;
}

// this method finds the lowest unique number in the data set
void lowestUnique(char *data) {
  // the players, used for the positions
  int players[20];
  // the count of each number
  // where the index is the number
  // index 1 = count of no. 1
  int count[10];
  // init each count to 0
  int i;
  for (i=0; i<10; i++)
    count[i] = 0;
  // extract the data
  int n = extractData(data, count, players);
  // find the lowest number
  int j;
  // flag for if found or not
  int lowest = -1;
  for (j=1; j<10; j++) {
    // if the current only has 1
    if (count[j] == 1) {
      // it's the lowest unique number
      lowest = j;
      // break out of for loop
      break;
    }
  }
  // if we didnt find a unique lowest num, print 0
  if (lowest == -1)
    printf("0\n");
  else {
    // else, find the position and print it out
    for (j=0; j<n; j++)
      if (players[j] == lowest) {
        // +1 because array is zero based, but answer requires 1 based
        printf("%i\n", j+1);
        break;
      }
  }
}

// this method extracts the data from the string
int extractData(char *data, int count[], int players[]) {
  // strip the spaces
  char *token = strtok(data, " ");
  // init an index counter
  int i = 0;
  // while token isn' null
  while (token) {
    // get the current number
    int num = atoi(token);
    // put the number into the corresponding player's position
    players[i++] = num;
    // increment the current numbers count
    count[num]++;
    // grab next token
    token = strtok(NULL, " ");
  }
  // return the index for the len of players array
  return i;
}
