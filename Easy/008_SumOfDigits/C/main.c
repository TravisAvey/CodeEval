#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1024

void sumOfDigits(char *);

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
        // call method to output the sum of the line
        // removing the newline for each line
        sumOfDigits(strtok(line, "\n"));
    }
    return 0;
}

/*
    This method outputs the sum of the digits
    passed as a string
    input as 23
    sum  = 2 + 3 -> 5
*/
void sumOfDigits(char *line)
{
    // init a sum
    int sum = 0;
    // init a index
    int i = 0;
    do
    {
        // convert the current char to an int
        int num = line[i++] - '0';
        // add current num to the sum
        sum += num;
    // as long as the current char isnt
    // the '\0' (end of the string)
    } while (line[i] != '\0');

    // output sum to stdout
    printf("%d\n", sum);
}