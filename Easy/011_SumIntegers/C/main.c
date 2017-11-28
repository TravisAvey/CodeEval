#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// buffer size
#define SIZE 512

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // declare a new char array of SIZE
    char line[SIZE];
    // init sum to 0
    int sum = 0;
    // while we can get a line from the file, SIZE chunk
    while (fgets(line, SIZE, file)) {
        // declare a token
        char *token;
        // tokenize the line, removing the new line
        token = strtok(line, "\n");
        // convert to int and add to sum
        sum += (int) strtol(token, (char **)NULL, 10);
    }
    // output the sum to stdout
    printf("%d\n", sum);
    return 0;
}

