#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256
#define SIZE 32

void roadTrip(char *);
int getData(char *, char *[]);
int getDistances(char *[], int, int []);
int compare(const void *, const void *);

int main(int argc, char **argv) {

    if (argc < 2) return EXIT_FAILURE;
    FILE *file = fopen(argv[1], "r");
    char line[BUF];
    while (fgets(line, BUF, file)) {
        if (line[0] == '\n') continue;
        char *token = strtok(line, "\n");
        roadTrip(token);
    }

    return EXIT_SUCCESS;
}

void roadTrip(char *line) {
    char *data[SIZE];
    int distances[SIZE];
    int i = getData(line, data);
    int j = getDistances(data, i, distances);
    qsort(distances, j, sizeof(int), compare);
    int k;
    for (k=0; k<j; k++)
        printf("Distance: %i\n", distances[k]);
    puts("---------");

}

int getData(char *line, char *data[]) {
    char *token = strtok(line, " ;");
    int i = 0;
    while (token) {
        data[i++] = token;
        token = strtok(NULL, " ;");
    }

    return i;
}

int getDistances(char *data[], int len, int distances[]) {
    int i;
    for (i=0; i<len; i++) {
        char *cityMiles = data[i];
        char *token = strtok(cityMiles, ",");
        token = strtok(NULL, ",");
        distances[i] = atoi(token);
    }

    return i;
}

int compare(const void *x, const void *y) {
    return ( *(int*) x - *(int*)y);
}