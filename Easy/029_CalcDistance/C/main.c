#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUF 256
#define SIZE 10

void calcDistance(char *);
int getDistance(int []);

int main(int argc, char **argv) {
  if (argc < 2)
    return EXIT_FAILURE;
  FILE *file = fopen(argv[1], "r");
  char line[BUF];
  while (fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    calcDistance(token);
  }
  return EXIT_SUCCESS;
}

void calcDistance(char *data) {
  int nums[SIZE];
  char *token = strtok(data, "(), ");
  int i = 0;
  while (token) {
    nums[i++] = atoi(token);
    token = strtok(NULL, "(), ");
  }
  int distance = getDistance(nums);
  printf("%i\n", distance);
}

int getDistance(int nums[]) {
  double x = ( (nums[2] - nums[0]) * (nums[2] - nums[0]) );
  double y = ( (nums[3] - nums[1]) * (nums[3] - nums[1]) );
  double sum = x + y;
  return (int) (sqrt(sum) );
  return 0;
}
