#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64
#define SIZE 12

void racingChars(char *[], int);


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: please  pass file to program\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    char *data[50];
    int i = 0;
    while(fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        data[i] = (char *) malloc(sizeof(char) * BUF);
        strcpy(data[i], token);
        i++;
    }
    racingChars(data, i);
    return EXIT_SUCCESS;
}


void racingChars(char *data[], int len) {
    
    char checkPoint = 'C';
    char gate       = '_';
    char straight   = '|';
    char left       = '/';
    char right      = '\\';
    
    int currentCheck;
    int currentGate;
    int lastPosition;

    int hasCheck = 0;
    int hasGate = 0;
    int firstRun = 1;

    int i, j;
    for (i=0; i<len; i++) {
        char *line = data[i];
        for (j=0; j<strlen(line); j++) {
            char ch = data[i][j];
            printf("%c ", ch);
        }
        puts("");
    }
}
