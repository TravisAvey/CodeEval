#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 64

enum months {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

void workExperience(char *);
int extractDates(char *, char *[]);
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

    char *dates[SIZE];
    int i = extractDates(data, dates);

    // dates is now array of time periods, w/o the leading
    // whitespace:
    // dates[0] = Feb 2004-Dec 2009
    // dates[1] = Sep 2004-Jul 2008



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
