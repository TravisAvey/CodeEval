#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUF 256
#define SIZE 10

void calcDistance(char *);
int getDistance(int []);

int main(int argc, char **argv) {
  // if not enough args, quit
  if (argc < 2)
    return EXIT_FAILURE;
  // open file
  FILE *file = fopen(argv[1], "r");
  // init string
  char line[BUF];
  // while we can get a line from the file
  while (fgets(line, BUF, file)) {
    // strip the \n from the line
    char *token = strtok(line, "\n");
    // calculate the distance
    calcDistance(token);
  }
  return EXIT_SUCCESS;
}

// This method outputs the distance
// between the points (x1, y1) (x2, y2)
void calcDistance(char *data) {
  // init an array to hold points
  int nums[SIZE];
  // strip the unneeded characters
  char *token = strtok(data, "(), ");
  // init and index counter
  int i = 0;
  // while token is not null
  while (token) {
    // convert to int and put into array
    nums[i++] = atoi(token);
    // get next token
    token = strtok(NULL, "(), ");
  }
  // get the distance
  int distance = getDistance(nums);
  // output said distance
  printf("%i\n", distance);
}

// This method calculates the distance
// between 2 points:
// returns square root of (x2-x1)^2 + (y2-y1)^2
int getDistance(int nums[]) {
  // get x component squared
  double x = ( (nums[2] - nums[0]) * (nums[2] - nums[0]) );
  // get the y component squared
  double y = ( (nums[3] - nums[1]) * (nums[3] - nums[1]) );
  // add the components together
  double sum = x + y;
  // square root the sum, convert to an integer and return
  return (int) (sqrt(sum) );
}
