#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    This method prints out the fizz buzz of the 
    params passed to method.
*/
void fizzBuzz(int fizz, int buzz, int limit)
{
    // loop from 1 to the limit
    for (int i=1; i<=limit; ++i)
    {
        // if divisible by both fizz and buzz, print FB
        if (i%fizz == 0 && i%buzz == 0)
            printf("FB");
        // if divisible by fizz print F
        else if (i%fizz == 0)
            printf("F");
        // if divisible by buzz print B
        else if (i%buzz ==0)
            printf("B");
        // else print the number
        else
            printf("%i",i);
        // print a blank space after 
        printf(" ");
    }
    // print a new line
    printf("\n");
}

int main (int argc, char *argv[])
{
    
    // open the file for reading
    FILE *file = fopen(argv[1], "r");
    // init a buffer to hold each line
    char buffer[1028];
    
    // while fgets is not null.  (pass in buffer, max num of chars to read, file)
    while (fgets(buffer, 1028, file) != NULL)
    {
        // init a counter
        int i  = 0;
        // init a string token, pass in string to break up and delimeter
        char *p = strtok(buffer, " ");
        // create a string array of 3 [fizz, buzz, limit]
        char *line[3];
        
        // while the token is not null
        while (p != NULL)
        {
            // input the token into the array, increment counter
            line[i++] = p;
            // set to next
            p = strtok(NULL, " ");
        }
        
        // call fizzBuzz method, atoi -> char * to int 
        fizzBuzz(atoi(line[0]), atoi(line[1]), atoi(line[2]));
        
    }
    return 0;
}
