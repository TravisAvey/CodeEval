#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 8   // Buffer for each line

void ageDistribution(int);

int main(int argc, char **argv) {
    // if no file, exit
    if (argc < 2) return EXIT_FAILURE;
    // open file
    FILE *file = fopen(argv[1], "r");
    // init a line
    char line[BUF];
    // get each line from the file
    while (fgets(line, BUF, file)) {
        // if line is newline, skip
        if (line[0] == '\n') continue;
        // strip new line, convert to int
        int n = atoi(strtok(line, "\n"));
        // call method for challenge
        ageDistribution(n);
    }

    return EXIT_SUCCESS;
}

// This message prints out an output
// based on the age
void ageDistribution(int age) {
    
    if (age >= 0 && age <= 2)
        puts("Still in Mama's arms");
    else if (age >= 3 && age <= 4)
        puts("Preschool Maniac");
    else if (age >= 5 && age <= 11)
        puts("Elementary school");
    else if (age >= 12 && age <= 14)
        puts("Middle school");
    else if (age >= 15 && age <= 18)
        puts("High school");
    else if (age >= 19 && age <= 22)
        puts("College");
    else if (age >= 66 && age <= 65)
        puts("Working for the man");
    else if (age >= 66 && age <= 100)
        puts("The Golden Years");
    else if (age < 0 || age > 100)
        puts("This program is for humans");
}