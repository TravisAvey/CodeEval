#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// L of each line was larger
// for this challenge than normal
#define BUF 12000
#define SIZE 128

void majorElement(char **);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) {
        fprintf(stderr, "Error.\nUsage: ./a.out file.txt\n");
        return EXIT_FAILURE;
    }
    // open file
    FILE *file = fopen(argv[1], "r");
    // init a string to hold each line
    char line[BUF];
    // get each line from file
    while(fgets(line, BUF, file)) {
        // if just new line, continue
        if (line[0] == '\n') continue;
        // strip new line from each line
        char *token = strtok(line, "\n");
        // call method to get the major element
        majorElement(&token);
    }
    return EXIT_SUCCESS;
}

// this method finds the major element
// in the data set.
// Where a number is present atleast
// L/2, where L is the number of items
void majorElement(char **data) {
    // init an array to hold all the numbers
    int nums[SIZE];
    // init the array for all elements set to zero
    int i;
    for (i=0; i<SIZE; i++) nums[i] = 0;

    // tokenize string on the commas
    char *token = strtok(*data, ",");
    // reset i to 0, to count the itmes
    i = 0;
    // while token is good
    while (token) {
        // covernt token to int
        int current = atoi(token);
        // get the count
        int count = nums[current];
        // increment the count
        nums[current] = ++count;
        // get next token
        token = strtok(NULL, ",");
        // increment the number of items
        i++;
    }
    // init the major element to 0
    int majorElement = 0;
    // loop over all the elements
    int j;
    for (j=0; j<SIZE; j++) {
        // get the count
        int count = nums[j];
        // if the count is greatern than L/2
        if (count >= i/2) {
            // set the major element
            majorElement = j;
        }
    }
    // if major element was set, output it
    if (majorElement)
        printf("%i\n", majorElement);
    // else output None
    else
        printf("None\n");
}