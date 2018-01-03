#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUF 512
#define SIZE 64

enum months {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

void workExperience(char *);
int extractDates(char *, char *[]);
int getDates(char *[], char *[], int);
void removeLeadSpace(char **);

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "ERROR: no file selected\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    while (fgets(line, BUF, file)) {
        char *token = strtok(line, "\n");
        workExperience(token);
    }
    return EXIT_SUCCESS;
}


void workExperience(char *data) {

    char *timePeriods[SIZE];
    char *dates[SIZE];
    int i = extractDates(data, timePeriods);
    int j = getDates(timePeriods, dates, i);
    
    int k;
    for (k=0; k<j; k++) {
        printf("dates[%i] = %s\n", k, dates[k]);
    }



}

// Helper method extracts the dates from the data
// and puts into the array
int extractDates(char *data, char *dates[]) {
    // tokenize the data on the semi-colon
    char *token = strtok(data, ";");
    // init index counter
    int i = 0;
    // while token is not null
    while (token) {
        // all but first token have leading whitespace, remove
        if (i != 0) removeLeadSpace(&token);
        // add time period to dates array
        dates[i++] = token;
        // grab next token
        token = strtok(NULL, ";");
    }
    // return the number of date periods
    return i;
}

// Helper method gets the dates from the times array
// which are in format of Mon YYYY-Mon YYYY, and puts
// in the dates array as just Mon YYYY
int getDates(char *times[], char *dates[], int len) {
    int i;
    int j = 0;
    // loop over number of items in times array
    for (i=0; i<len; i++) {
        // tokenize string on the -
        char *token = strtok(times[i], "-");
        // while the token is not null
        while (token) {
            // add to dates array
            dates[j++] = token;
            // get next token
            token = strtok(NULL, "-");
        }
    }
    // return the number of dates
    return j;
}

// Helper method removes the leading whitespace
// from the data.  Used char ** to actually
// change the value of the string passed
void removeLeadSpace(char **data) {
    // loop until not whitespace
    int i;
    for (i=0; (*data)[i] == ' '; i++) {}
    // add i to data array
    *data += i;
}
