#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512
#define SIZE 256

void queryBoard(char *);
void setCol(int [SIZE][SIZE], char *);
void setRow(int [SIZE][SIZE], char *);
int queryCol(int [SIZE][SIZE], char *);
int queryRow(int [SIZE][SIZE], char *);

int main(int argc, char **argv) {
  

  FILE *file = fopen(argv[1], "r");

  char line[BUF];

  while(fgets(line, BUF, file)) {
    char *token = strtok(line, "\n");
    queryBoard(token);
  }

  return EXIT_SUCCESS;
}


void queryBoard(char *line) {
  int board[SIZE][SIZE];  
  char *data[3];
  char *query = strtok(line, " ");
  if (strcmp(query, "SetCol") == 0)
    setCol(board, line);
  else if (strcmp(query, "SetRow") == 0)
    setRow(board, line);
  else if (strcmp(query, "QueryCol") == 0)
    queryCol(board, line);
  else if (strcmp(query, "QueryRow") == 0)
    queryRow(board, line);
}

void setCol(int board[SIZE][SIZE], char *data) {
  printf("Calling set col\n");
}

void setRow(int board[SIZE][SIZE], char *data) {
  printf("Calling set row\n");
}

int queryCol(int board[SIZE][SIZE], char *data) {
  printf("calling query col\n");
  return 0;
}

int queryRow(int board[SIZE][SIZE], char *data) {
  printf("calling query row\n");
  return 0;
}
