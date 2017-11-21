#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1024

void lowercase(char *, size_t);
int getLower(int);

int main(int argc, char **argv)
{
    // open the file as read only
    FILE *file = fopen(argv[1], "r");

    // declare a char array to hold each line
    char line[SIZE];
    // while we can get a line out of the file
    // in 1024 bytes at a time
    while(fgets(line, SIZE, file))
    {
        // get the count of the line
        size_t count = sizeof(line) / sizeof(line[0]);
        // call method to lowercase the line
        lowercase(line, count);
    }
    return 0;
}

// this method loops over the line and
// changes each char to a lower case
void lowercase(char *line, size_t count)
{
    // declare index
    int i;
    // loop through current line
    for (i=0; i<count; i++)
        // set the current char to lowercase
        line[i] = getLower(line[i]);
    // output to stdout
    printf("%s", line);
}

// this method returns the
// lowercase version
// if the char is 'A' = 65,
// we add 32 to 65 getting 97 = 'a'
int getLower(int c)
{
    // if c is::
    if ((c >=65 && c <= 90))
        // add 32
        c += 32;
    // return new value for lowercase
    return c;
}