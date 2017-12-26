#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256
#define SIZE 20

void swapElements(char *);
int extractData(int [], char **, char *);

int main(int argc, char **argv) {
    if (argc < 2) return EXIT_FAILURE;
    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    while (fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        swapElements(token);
    }

    return EXIT_SUCCESS;
}

/*
    input example:
    1 2 3 4 5 6 7 8 9 : 0-8
    output:
    9 2 3 4 5 6 7 8 1
*/
void swapElements(char *data) {
    int array[SIZE];
    char *swaps;
    int i = extractData(array, &swaps, data);
    printf("swaps : %s\n", swaps);

    int j;
    for (j=0; j<i; j++)
        printf("%i ", array[j]);
    puts("");
}

int extractData(int array[], char **pos, char *data) {
    char *token = strtok(data , ":");
    char *numbers = token;
    token = strtok(NULL, ":");
    *pos = token;

    char *tok = strtok(numbers, " ");
    int i = 0;
    while (tok) {
        array[i++] = atoi(tok);
        tok = strtok(NULL, " ");
    }

    return i;
}