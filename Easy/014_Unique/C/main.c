#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a buffer for each line
#define BUFFER 512

void printUnique(char *, int);

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // init a char array with size of BUFFER
    char line[BUFFER];

    // while we can get a line from the file, BUFFER amount at a time
    while (fgets(line, BUFFER, file)) {
        // get the length (divide by 2 + 1 for commas)
        size_t len = (sizeof line / sizeof line[0]) / 2 + 1;
        // call method to print the unique
        printUnique(line, len);
    }

    return 0;
}

/*
    This method prints the unique numbers from line
    ex: 1,1,1,2,3,3,4,4,4,4
    output: 1,2,3,4
*/
void printUnique(char *line, int size) {
    // create an integer array with the size
    int nums[size];
    // init n to 0
    int n = 0;
    // declare a string
    char *token;
    // string to token, removing any coma or newline
    token = strtok(line, ",\n");
    // while token is not null
    while (token != NULL) {
        // convert to int and put into nums array
        nums[n++] = (int) strtol(token, (char **)NULL, 10);
        // get next token
        token = strtok(NULL, ",\n");
    }

    // declare index counters
    int i;
    int j=0;
    // create unique array of size n, from above
    int unique[n];
    // loop over the nums array
    for (i=0; i<n; i++) {
        // while we are not at the end of the array
        // and while curren num is the same as next
        while (i<n-1 && (nums[i] == nums[i+1])) {
            // increment i
            i++;
        }
        // store the unique number
        unique[j++] = nums[i];
    }

    // output the unique array
    for (i=0;i<j-1;i++)
        printf("%d,", unique[i]);
    printf("%d\n", unique[i]);
}