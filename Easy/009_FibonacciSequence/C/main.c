#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1024

void fibonacci(char *);

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
        // call method to output the nth fibonacci
        // removing the newline for each line
        fibonacci(strtok(line, "\n"));
    }
    return 0;
}

/*
    This method prints out the nth fibonacci
    in the sequence
*/
void fibonacci(char *num)
{
    // convert the string to an integer
    int n = (int) strtol(num, (char **)NULL, 10);
    // init a new array (we want the nth, 0 based, so n+1)
    int fib[n+1];

    // first 2 in sequence
    fib[0] = 0;
    fib[1] = 1;
    int i;
    // loop from 2 to n
    for (i=2; i<=n;i++)
        // F(n) = F(n-1) + F(n-2)
        fib[i] = fib[i-1] + fib[i-2];
    
    // output the nth fibonacci to stdout
    printf("%d\n", fib[n]);
}