#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64  // Buffer size
#define SIZE 50 // Number of lines

void racingChars(char *[], int);


int main(int argc, char **argv) {
    // if no file passed, exit
    if (argc < 2) {
        fprintf(stderr, "Error: please  pass file to program\n");
        return EXIT_FAILURE;
    }
    // open file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // init an array of strings
    char *data[SIZE];
    // init index counter
    int i = 0;
    // while we can get a line from the file
    while(fgets(line, BUF, file)) {
        // if just new line, skip
        if (line[0] == '\n') continue;
        // strip newline from current line
        char *token = strtok(line, "\n");
        // allocate memory for current array item
        data[i] = (char *) malloc(sizeof(char) * BUF);
        // copy the current line into array
        strcpy(data[i], token);
        // increment counter
        i++;
    }
    // call method to output the racing chars
    racingChars(data, i);
    return EXIT_SUCCESS;
}

// This method outputs the racing chars
// dependent on previous lines, if the
// char goes straight, left or right
void racingChars(char *data[], int len) {
    
    char checkPoint = 'C';  // checkpoint char
    char gate       = '_';  // gate char
    char straight   = '|';  // straight char
    char left       = '/';  // left char
    char right      = '\\'; // right char
    
    int currentCheck;       // current checkpoint location
    int currentGate;        // current gate location
    int lastPosition;       // last position location

    int hasCheck    = 0;    // boolean if has checkpoint
    int hasGate     = 0;    // boolean if has gate
    int first       = 1;    // boolean if first iteration

    // loop over the number of strings in the data array
    int i, j;
    for (i=0; i<len; i++) {
        // get current line
        char *line = data[i];
        // loop over the number of chars in the line
        for (j=0; j<strlen(line); j++) {
            // get current char
            char ch = data[i][j];
            // if this is a checkpoint
            if (ch == checkPoint) {
                // set the current checkpoint
                currentCheck = j;
                // set the boolean to true
                hasCheck = 1;
            // if char is a gate
            } else if (ch == gate) {
                // set current gate location
                currentGate = j;
                // set bool to true
                hasGate = 1;
            }
        }
        // if first run
        if (first) {
            // set first to false
            first = 0;
            // if this was a check point
            if (hasCheck) {
                // set last position (for next iteration)
                lastPosition = currentCheck;
                // replace check with straight
                data[i][currentCheck] = straight;
            // if has a gate
            } else if (hasGate) {
                // set last position (for next iteration)
                lastPosition = currentGate;
                // replace gate with straight
                data[i][currentGate] = straight;
            }
        // not first run
        } else {
            // if has checkpoint
            if (hasCheck) {
                // if the last posisition is same as check
                if (lastPosition == currentCheck) {
                    // replace check with stright
                    data[i][currentCheck] = straight;
                // if the last position is less than check
                } else if (lastPosition < currentCheck) {
                    // replace with right
                    data[i][currentCheck] = right;
                // if the last position is greater than check
                } else if (lastPosition > currentCheck) {
                    // replace with left
                    data[i][currentCheck] = left;
                }
                // set the last position for next
                lastPosition = currentCheck;
            // if has gate, but not a check point
            } else if (hasGate && !hasCheck) {
                // if last pos is same
                if (lastPosition == currentGate) {
                    // replace gate with straight
                    data[i][currentGate] = straight;
                // if less than
                } else if (lastPosition < currentGate) {
                    // replace with right
                    data[i][currentGate] = right;
                // if greater than
                } else if (lastPosition > currentGate) {
                    // replace with left
                    data[i][currentGate] = left;
                }
                // set last position
                lastPosition = currentGate;
            }
        }
        // output the line
        printf("%s\n", line);
        // set check & gate booleans to false for next iteration
        hasCheck = 0;
        hasGate = 0;
        
    }
}
