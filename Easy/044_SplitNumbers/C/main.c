#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

void splitNumbers(char *);
void extractData(char *, char **, char **);

int main(int argc, char **argv) {
    if (argc < 2) return EXIT_FAILURE;

    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    while (fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        splitNumbers(token);
    }

    return EXIT_SUCCESS;
}

void splitNumbers(char *data) {

    char *numbers, *pattern;
    extractData(data, &numbers, &pattern);
    
}

void extractData(char *data, char **numbers, char **pattern) {
    char *token = strtok(data, " ");
    *numbers = token;
    token = strtok(NULL, " ");
    *pattern = token;
}