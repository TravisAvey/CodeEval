#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512   // Buffer
#define SIZE 256  // array size

// Method declarations
void queryBoard(int [SIZE][SIZE], char *);
void initBoard(int [SIZE][SIZE]);
void setCol(int [SIZE][SIZE], int, int);
void setRow(int [SIZE][SIZE], int, int);
int queryCol(int [SIZE][SIZE], int);
int queryRow(int [SIZE][SIZE], int);

int main(int argc, char **argv) {
  // open the file passed from argv[1]
  FILE *file = fopen(argv[1], "r");
  // init a string to hold each line
  char line[BUF];
  // init a double array
  int board[SIZE][SIZE];
  // initialze the board
  initBoard(board);
  // while we can get a line from the file
  while(fgets(line, BUF, file)) {
    // strip the newline
    char *token = strtok(line, "\n");
    // call method to query the board
    queryBoard(board, token);
  }
  return EXIT_SUCCESS;
}

/*
  This method parses the string and calls
  the appropriate methods
*/
void queryBoard(int board[SIZE][SIZE], char *line) {
  // get the first token, will be instruction
  char *query = strtok(line, " ");
  // if  SetCol
  if (strcmp(query, "SetCol") == 0) {
    // get the column and val from the string
    // converting each to an integer value
    query = strtok(NULL, " ");
    int col = atoi(query);
    query = strtok(NULL, " ");
    int val = atoi(query);
    // call method to set the column
    setCol(board, col, val);
  }
  // if SetRow
  else if (strcmp(query, "SetRow") == 0) {
    // get the row and the val from the string
    // converting each to an int
    query = strtok(NULL, " ");
    int row = atoi(query);
    query = strtok(NULL, " ");
    int val = atoi(query);
    // call method to set the row
    setRow(board, row, val);
  }
  // if QueryCol
  else if (strcmp(query, "QueryCol") == 0) {
    // get the col, convert to int
    query = strtok(NULL, " ");
    int col = atoi(query);
    // call method that queries the column
    int sum = queryCol(board, col);
    // output the sum of the column
    printf("%i\n", sum);
  }
  // if QueryRow
  else if (strcmp(query, "QueryRow") == 0) {
    // get the row, convert to int
    query = strtok(NULL, " ");
    int row = atoi(query);
    // call method that queries the row
    int sum = queryRow(board, row);
    // output the sum of the row
    printf("%i\n", sum);
  }
}

/*
  This method sets the column of the board to the value passed
*/
void setCol(int board[SIZE][SIZE], int col, int val) {
  int i;
  for (i=0; i<SIZE; i++)
    board[i][col] = val;
}
/*
  This method sets the row of the board to the value passed
*/
void setRow(int board[SIZE][SIZE], int row, int val) {
  
  int i;
  for (i=0; i<SIZE; i++)
    board[row][i] = val;

}

/*
  This method queries the column
*/
int queryCol(int board[SIZE][SIZE], int col) {
  // init a sum
  int sum = 0;
  // loop over the board
  int i;
  for (i=0; i<SIZE; i++)
    // add the columns value to the sum
    sum += board[i][col];
  // return the sum
  return sum;
}

/*
  This method queries the row
*/
int queryRow(int board[SIZE][SIZE], int row) {
  // init a sum
  int sum = 0;
  // loop over the board
  int i;
  for (i=0; i<SIZE; i++)
    // add the rows value to the sum
    sum += board[row][i];
  // return the sum
  return sum;
}

/*
  This method initilizes the board
  Each row and col set to 0
*/
void initBoard(int board[SIZE][SIZE]) {
  int i, j;
  for (i=0; i<SIZE; i++)
    for (j=0; j<SIZE;j++)
      board[i][j] = 0;
}
