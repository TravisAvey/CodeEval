#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

void reverseWords(char *line);

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
        // call method to reverse the words
        reverseWords(line);
    }
    return 0;
}

void reverseWords(char *line)
{
    // define a string array to hold the words
    char *words[SIZE];
    // declare a char pointer to hold the tokens
    char *token;
    // init a counter
    int i = 0;
    // grab the first token from the line
    token = strtok(line, " \n");
    // while each token is not null
    while (token != NULL)
    {
        // store the token into the words array
        // and increment i for the next word
        words[i++] = token;
        // grab the next token
        token = strtok(NULL, " \n");
    }

    // init j to be 1 less than i
    int j = i-1;
    // loop down through the words array
    // and print to stdout the words
    // in reverse
    for (j; j>=0; j--)
        printf("%s ", words[j]);
    printf("\n");


}