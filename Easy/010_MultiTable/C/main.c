#include <stdio.h>

int main(int argc, char *argv) {
    // declare counters
    int i;
    int j;
    // loop through 12 x 12
    for (i=1; i<=12;i++) {
        for(j=1; j<=12;j++) {
            // output i*j with width of 4
            printf("%4d", i*j);
        }
        // print new line for new column
        printf("\n");
    }
    return 0;
}