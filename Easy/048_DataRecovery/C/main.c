#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512 // Buffer size
#define SIZE 64 // Array Size

void dataRecovery(char *);
int extractData(char *, char *[], int []);
int findMissing(int [], int);

int main(int argc, char **argv) {
    // if no file, output error and exit
    if (argc < 2) {
        fprintf(stderr, "Error: no file selected\n");
        return EXIT_FAILURE;
    }
    // open the file
    FILE *file = fopen(argv[1], "r");
    // create a string
    char line[BUF];
    // while we can get a line
    while (fgets(line, BUF, file)) {
        // if line is just a new line, skip
        if (line[0] == '\n') continue;
        // strip out newline
        char *token = strtok(line, "\n");
        // call method for data recovery
        dataRecovery(token);
    }
    return EXIT_SUCCESS;
}

// This method gets the data from the
// string and outputs in correct order
void dataRecovery(char *data) {
    // init arrays
    char *words[SIZE];
    int positions[SIZE];
    char *inOrder[SIZE];
    // extract the data and put into arrays
    int i = extractData(data, words, positions);
    // find the missing number from sequence in 
    // the positions array
    int missing = findMissing(positions, i);
    // loop through the word count -1 (b/c missing)
    int j;
    for (j=0; j<i-1; j++) {
        // get pos, array is 0 based
        // but the numbers in data are 1
        int pos = positions[j] - 1;
        // put the word in correct place
        inOrder[pos] = words[j];
    }
    // finally put the missing word in it's place (always the last)
    inOrder[missing-1] = words[i-1];

    // output correct order of words
    for (j=0; j<i-1; j++)
        printf("%s ", inOrder[j]);
    printf("%s\n", inOrder[j]);

}

// This method extracts the data and puts into
// the two arrays;
// returns the number of words
int extractData(char *data, char *w[], int p[]) {
    // tokenize on a semi colon
    char *token = strtok(data, ";");
    char *words = token;
    token = strtok(NULL, ";");
    char *nums = token;
    
    // put the words into the array
    char *tok = strtok(words, " ");
    int i = 0;
    while (tok) {
        w[i++] = tok;
        tok = strtok(NULL, " ");
    }

    // put the numbers into the array
    char *tkn = strtok(nums, " ");
    int j = 0;
    while (tkn) {
        p[j++] = atoi(tkn);
        tkn = strtok(NULL, " ");
    }

    // return the word count
    return i;
}

// This method finds the missing number
// from the sequence
//
// Get sum of main sequence (as if not missing)
// sum up the sequence with missing number
// return the main Sum - the sum
int findMissing(int nums[], int len) {
    // get the main sequence
    int mSum = len * (len + 1) / 2;
    // init a sum to 0
    int sum = 0;
    // loop and add current to sum
    int i;
    for (i=0; i<len-1; i++) {
        sum += nums[i];
    }
    // return the difference, which
    // is exaclty the missing number
    return mSum - sum;
}