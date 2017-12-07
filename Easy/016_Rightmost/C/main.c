#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a buffer for each line
#define BUFFER 1024

void rightMostChar(char *);

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // init a char array with size of BUFFER
    char line[BUFFER];

    // while we can get a line from the file, BUFFER amount at a time
    while (fgets(line, BUFFER, file)) {
        rightMostChar(line);
    }

    return 0;
}

/*
    This method outputs the right most char
    given a line with a char.
    Example:
    Hello World,r
    8
*/
void rightMostChar(char *line) {
    // init a string for the words
    char *data;
    // init a char to hold the char in question
    char right;
    // init a string to tokenize the line
    char *token;

    // get the first part of the line, parse on , and newlines
    token = strtok(line, ",\n");
    // set the data string
    data = token;
    // get the second part of the line
    token = strtok(NULL, ",\n");
    // set the right char
    right = token[0];

    // init a index counter
    int i;
    // loop through the data string untill we
    // get to a '\0', this will be the length
    // of the characters in the data
    for (i=0;data[i]!='\0';i++);
    
    // init a location to -1
    int loc = -1;
    // loop through the data
    int j;
    for (j=0;j<i;j++) {
        // if the current char is
        // the same as the right char
        if (data[j] == right)
            // set the loc
            loc = j;
    }
    // print loc. will be -1 if not in string
    // or will be the right most char in the string
    printf("%i\n", loc);

}
