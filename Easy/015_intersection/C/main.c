#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a buffer for each line
#define BUFFER 512

void getIntersection(char *);
void extractData(char *, char **);
int convertData(char *, int *);


int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // init a char array with size of BUFFER
    char line[BUFFER];

    // while we can get a line from the file, BUFFER amount at a time
    while (fgets(line, BUFFER, file)) {
        getIntersection(line);
    }

    return 0;
}

/*
    This method prints out the intersection of
    integers where they intersect:
    3,4,5,6;4,5,6,7,8
    4,5,6
*/
void getIntersection(char *line) {

    // the data, 2 strings split on a ;
    char *data[2];
    // extract the data
    extractData(line, data);

    // Declare 2 arrays to hold the integers
    int A[128];
    int B[128];
    // convert the char array data to int arrays
    int i = convertData(data[0], A);
    int j = convertData(data[1], B);
   
    // declare new array to hold the answer
    int C[128];
    // declare counters
    int n = 0;
    int m = 0;
    int k = 0;

    // while we are less than A and B
    while (n < i && m < j) {
        // if they are equal
        if (A[n] == B[m]) {
            // add A to answer array
            C[k++] = A[n];
            // increment both
            n++;
            m++;
        // else if A is greater than B
        } else if (A[n] > B[m]) {
            // incrment B
            m++;
        } else {
            // else, B is greater increment A
            n++;
        }
    }

    // if we have an answer
    if (k > 0) {
        // loop through C, less than last
        for (i=0; i<k-1; i++)
            // output all but last including comma for each
            printf("%d,", C[i]);
        // for last, no comma and new line
        printf("%d\n", C[i]);
    // else no answer, just output new line
    } else {
        printf("\n");
    }
}


/*
    This method extracts the data from the line
    passed and splits on ';' into an array
*/
void extractData(char *line, char *data[]) {

    char *tok;
    tok = strtok(line, ";\n");
    data[0] = tok;
    tok = strtok(NULL, ";\n");
    data[1] = tok;
}

/*
    This method converts the string into
    an integer array.  Returns the last
    index of the parsed data
*/
int convertData(char *data, int *arr) {
    char *token;
    token = strtok(data, ",");
    int i = 0;
    while (token != NULL) {
        arr[i++] = atoi(token);
        token = strtok(NULL, ",");
    }

    return i;
}