#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 64
#define SIZE 32

void juggleZeros(char *);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) {
        fprintf(stderr, "Error: No File\nExiting..\n");
        return EXIT_FAILURE;
    }
    // open the file
    FILE *file = fopen(argv[1], "r");
    // init a string
    char line[BUF];
    // get each line of the file
    while (fgets(line, BUF, file)) {
        // if new line, skip
        if (line[0] == '\n') continue;
        // strip new lines
        char *token = strtok(line, "\n");
        juggleZeros(token);
    }
}

// this method handles converting the
// sequence of zeros into a binary number
// then converting to a integer
void juggleZeros(char *line) {
    
    int len = strlen(line);
    int i = 0;
    char *zeros[SIZE];
    char *token = strtok(line, " ");
    while (token) {
        zeros[i++] = token;
        token = strtok(NULL, " ");
    }

    int j = 0;
    char *current;
    while (j < i) {
        char *flag = zeros[j];
        // if flag is 0
        if (strcmp(flag, "0") == 0) {
            // get next string of zeros
            current = zeros[++j];
            printf("%s", current);
        } else {
            // get next string of zeros
            current = zeros[++j];

            int k;
            for (k=0; k<strlen(current); k++)
                printf("1");
        }
        j++;
    }
    puts("");
}