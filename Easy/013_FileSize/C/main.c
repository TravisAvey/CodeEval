#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // open the file passed as 1st arguement
    FILE *file = fopen(argv[1], "r");
    // seek to the end of the file
    fseek(file, 0L, SEEK_END);
    // now we can get the size with ftell(FILE*)
    long int size = ftell(file);
    // output to stdout the file size
    printf("%ld\n", size);

    return 0;
}
