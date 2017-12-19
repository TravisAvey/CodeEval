#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 256

void queryBoard(int [SIZE][SIZE], char *);
void initBoard(int [SIZE][SIZE]);
void setCol(int [SIZE][SIZE], int, int);
void setRow(int [SIZE][SIZE], int, int);
int queryCol(int [SIZE][SIZE], int);
int queryRow(int [SIZE][SIZE], int);

int main(int argc, char **argv) {
  

  FILE *file = fopen(argv[1], "r");

  char line[BUF];
  int board[SIZE][SIZE];
  initBoard(board);
  while(fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    queryBoard(board, token);
  }

  return EXIT_SUCCESS;
}


void queryBoard(int board[SIZE][SIZE], char *line) {
  
  char *query = strtok(line, " ");
  if (strcmp(query, "SetCol") == 0) {
    query = strtok(NULL, " ");
    int col = atoi(query);
    query = strtok(NULL, " ");
    int val = atoi(query);
    setCol(board, col, val);
  }
  else if (strcmp(query, "SetRow") == 0) {
    query = strtok(NULL, " ");
    int row = atoi(query);
    query = strtok(NULL, " ");
    int val = atoi(query);
    setRow(board, row, val);
  }
  else if (strcmp(query, "QueryCol") == 0) {
    query = strtok(NULL, " ");
    int col = atoi(query);
    int sum = queryCol(board, col);
    printf("%i\n", sum);
  }
  else if (strcmp(query, "QueryRow") == 0) {
    query = strtok(NULL, " ");
    int row = atoi(query);
    int sum = queryRow(board, row);
    printf("%i\n", sum);
  }
}

void setCol(int board[SIZE][SIZE], int col, int val) {
  
  int i;
  for (i=0; i<SIZE; i++)
    board[i][col] = val;

}

void setRow(int board[SIZE][SIZE], int row, int val) {
  
  int i;
  for (i=0; i<SIZE; i++)
    board[row][i] = val;

}

int queryCol(int board[SIZE][SIZE], int col) {
  int sum = 0;
  int i;
  for (i=0; i<SIZE; i++)
    sum += board[i][col];
  return sum;
}

int queryRow(int board[SIZE][SIZE], int row) {
  int sum = 0;
  int i;
  for (i=0; i<SIZE; i++)
    sum += board[row][i];
  return sum;
}

void initBoard(int board[SIZE][SIZE]) {
  int i, j;
  for (i=0; i<SIZE; i++)
    for (j=0; j<SIZE;j++)
      board[i][j] = 0;
}
