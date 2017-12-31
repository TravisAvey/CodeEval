#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 1024 // buffer size
#define SIZE 256 // Array size

void roadTrip(char *);
int getData(char *, char *[]);
int getDistances(char *[], int, int []);
int compare(const void *, const void *);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) return EXIT_FAILURE;
    // open the file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // get each line from the file
    while (fgets(line, BUF, file)) {
        // if line is just a new line, skip
        if (line[0] == '\n') continue;
        // strip the new line
        char *token = strtok(line, "\n");
        // get the road trip
        roadTrip(token);
	//printf("%s\n", token);
    }
    return EXIT_SUCCESS;
}

// this method outputs the distances
// for the road trip
void roadTrip(char *line) {
    // declare arrays to hold the data and distances
    char *data[SIZE];
    int distances[SIZE];
    // get the data and the distances
    int i = getData(line, data);
    int j = getDistances(data, i, distances);
    // quick sort the distances
    qsort(distances, j, sizeof(int), compare);
    
    int currentPos = 0;
    int k;
    for (k=0; k<j-1; k++) {
        printf("%i,", distances[k] - currentPos);
        currentPos = distances[k];
    }
    printf("%i\n", distances[k] - currentPos);
    
}

// this method extracts the data from the line
// and returns the number of items found
int getData(char *line, char *data[]) {
    // each city separated by a ;
    char *token = strtok(line, " ;");
    int i = 0;
    while (token) {
        // put the data in array
        data[i++] = token;
        // get next token
        token = strtok(NULL, " ;");
    }
    return i;
}

// this method gets the distances from the value pairs
// and returns the number of items found
// example city,512
// adds 512 to distances[], returns 1
int getDistances(char *data[], int len, int distances[]) {
    // loop over the number of items in the data
    int i;
    for (i=0; i<len; i++) {
        // store the value pair
        char *cityMiles = data[i];
        // get the first token, will be city
        char *token = strtok(cityMiles, ",");
        // get what we want the miles
        token = strtok(NULL, ",");
        // store the miles
        distances[i] = atoi(token);
    }
    // return number of distances found
    return i;
}

// this method used for quick sort
// compare the two items and return the difference
int compare(const void *x, const void *y) {
    return ( *(int *)x - *(int *)y);
}
