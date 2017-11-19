#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void multiplesNumber(char *line);

int main(int argc, const char **argv) 
{
    // open the file passed as first 
    // argument
    FILE *file = fopen(argv[1], "r");
    // declare a char array to hold each line
    char line[SIZE];
    // while we get a string from the file
    while (fgets(line, SIZE, file)) 
    {
        multiplesNumber(line);
    }
    return 0;
}

/*
    This method finds the smallest multiple of a
    number (n) that is greater than or equal to another (x)
*/
void multiplesNumber(char *line)
{
    // declare a token
    char *token;
    // get the first and second token and convert to int, base 10
    token = strtok(line, ",\n");
    int x = (int) strtol(token, (char **)NULL, 10);
    token = strtok(NULL, ",\n");
    int n = (int) strtol(token, (char **)NULL, 10);

    // declare a counter index and a mulitple
    int i;
    int multiple;
    // loop from 1 to x
    for (i=1; i<=x; i++)
    {
        // get the multiple of n
        multiple = n * i;
        // if current multiple is greater than or equal
        if (multiple >= x)
        {
            // output answer to stdout and break
            printf("%d\n", multiple);
            break;
        }
    }
}