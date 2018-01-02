#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64
#define SIZE 12

void racingChars(char *);


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Error: please  pass file to program\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    int i = 0;
    while(fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        racingChars(token);
    }
    return EXIT_SUCCESS;
}


void racingChars(char *data) {
    static int prev = -1;
    int check = 0;
    int len = strlen(data);
    int i;
    for (i=0; i<len; i++) {

        if (data[i] == 'C') {
            prev = i;
        } else if (data[i] == '_') {
            prev = i;
        }
    }
 
    
}
