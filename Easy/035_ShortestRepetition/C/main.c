#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

int main(int argc, char **argv) {
    if (argc < 2) return EXIT_FAILURE;

    FILE *file = fopen(argv[1], "r");

    char line[BUF];

    while (fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        printf("%s\n", token);
    }

    return EXIT_SUCCESS;
}