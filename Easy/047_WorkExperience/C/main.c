#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 64

enum months {
    JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

void workExperience(char *);

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
    char *token = strtok(data, ";");
    int i = 0;
    while (token) {
        dates[i++] = token;
        token = strtok(NULL, ";");
    }

    int j;
    for (j=0; j<i; j++) {
        printf("%s::", dates[j]);
    }
    puts("");

}