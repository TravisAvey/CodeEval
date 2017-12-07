#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a buffer for each line
#define BUFFER 1024

int happyNumber(char *);
int *parseDigits(int);

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // init a char array with size of BUFFER
    char line[BUFFER];

    // while we can get a line from the file, BUFFER amount at a time
    while (fgets(line, BUFFER, file)) {
        printf("%i\n",happyNumber(line));
    }

    return 0;
}

// returns 1 if happy number
// or 0 if not a happy number
int happyNumber(char *line) {

    // declare a string to hold the token
    char *token;
    // remove the newline
    token = strtok(line, "\n");
    // convert to an int
    int N = atoi(token);
    // if N is already 1, return 1
    if (N == 1) return 1;
    // copy over number
    int num = N;
    // init a counter
    int n = 0;
    // while we only try 25 times to find a happy number
    while (n <= 25) {
        // init sum to 0 each iteration
        int sum = 0;
        // get an array of the digits
        int *nums = parseDigits(num);
        // declare an index counter
        int i;
        // loop over all the digits...
        for (i=0; i<10; i++)
            // add to the sum the square of each digit
            sum += nums[i] * nums[i];

        // if we got a 1 for the sum, return 1.. is happy number
        if (sum == 1)
            return 1;
        
        // increment the counter
        n++;
        // reset the sum to num
        num = sum;
    }
    // fall off while loop, not a happy number
    return 0;
}

/*
    This method parses the digits, and returns
    an array of the digits..

    example:
    123
    will return an array of
    1,2,3,0,0,0,0,0,0,0

    extra zeros was necessay when allocating the memory
*/
int *parseDigits(int N) {

    // allocate the memory for 10 integers
    int *nums = malloc(sizeof(int) * 10);
    // declare an index counter
    int i;
    // store the last digit in the array, by getting the modulus 10
    // next divide the number by 10, removing the last digit..
    // 1st: 123, 123 % 10 stores 3, 123 / 10 = 12
    // 2nd: 12, 12 % 10 stores 2, 12 / 10 = 1
    // 3rd: 1, 1 % 10 stores 1, 1 / 10 = 0
    for (i=0;N > 0; N /= 10, i++)
        nums[i] = N % 10;
    // return the array of the digits, plus 0s from malloc
    return nums;
}