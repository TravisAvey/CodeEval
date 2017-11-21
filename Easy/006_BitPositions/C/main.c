#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50

void bitPosition(char *line);
int getBit(unsigned int n, int pos);
int compareBits(unsigned int n, int a, int b);

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
        bitPosition(line);
    }
    return 0;
}

/*
    This method handles getting the data
    from the line and calling the helper
    methods to find if the bits are the same
*/
void bitPosition(char *line)
{
    // declare a string to hold the token
    char *token;
    // init a string for the delimeters
    char *delim = ",\n";

    // get the first token from the line
    token = strtok(line, delim);
    // convert the token to a 10 based unsigned int
    unsigned int n = (unsigned int) strtol(token, (char**)NULL, 10);

    // get the next token
    token = strtok(NULL, delim);
    // convert the token to an int
    int a = (int) strtol(token, (char**)NULL, 10);

    // get the next token
    token = strtok(NULL, delim);
    // convert token to an int
    int b = (int) strtol(token, (char**)NULL, 10);

    // call method to compare bits
    /*
        I was almost there without looking
        at C++ answer.. this is where the
        issue was. The ints are 1 based,
        needed to decrment to be 0 based
    */
    if (compareBits(n, --a, --b))
        printf("true\n");
    else
        printf("false\n");
    
}
 
/*
    Helper method that extracts the bit
*/
int getBit(unsigned int n, int pos)
{
    return (n & (1 << pos)) >> pos;
}

/*
    Helper method that returns 0/1 based on
    if the bits are the same or not
*/
int compareBits(unsigned int n, int a, int b)
{
    if (getBit(n, a) ^ (getBit(n, b)))
        return 0;
    else
        return 1;
}