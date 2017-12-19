#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 20

void simpleSort(char *);
int extractData(char *, double [SIZE]);
int compare(const void *, const void *);

int main(int argc, char **argv) {

  FILE *file = fopen(argv[1], "r");
  char line[BUF];

  while (fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    simpleSort(token);
  
  }
  return EXIT_SUCCESS;
}

void simpleSort(char *line) {
  double nums[SIZE];  
  int elements = extractData(line, nums);
  
  qsort(nums, elements, sizeof(double), compare);

  int i;
  for (i=0; i<elements; i++)
    printf("%.3f ", nums[i]);
  puts("");

}

int extractData(char *line, double nums[SIZE]) {

  char *token;
  int i=0;
  token = strtok(line, " ");
  
  while (token != NULL) {
    nums[i++] = atof(token);
    token = strtok(NULL, " ");
  }
  return i;

}

int compare(const void *x, const void *y) {
  
  return (*(double *)x) - (*(double *)y);
}
