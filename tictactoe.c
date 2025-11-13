#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//functions init
void printboard(char boardmain[][100], int boardsizearr);



int main() {
  int boardsize = 1;
  int mode = 0;
  int scorep1 = 0, scorep2 = 0, scoreai = 0, round=0;
  int x, y;
  puts("Weclome to tic tac toe");
while(boardsize < 3 || boardsize > 10){
  puts("input your desired board size (3-10)");
  scanf("%d", &boardsize);
  if(boardsize < 3 || boardsize > 10){
    puts("invalid board size, please try again");
  }
}




int boardsizearr = (boardsize * 2) - 1;
while(mode != 1 && mode != 2){
  puts( "Would you like to play against Ai or another player? (1 for player 2 for Ai)");
  scanf("%d", &mode);
    if(mode != 1 && mode != 2){
        puts("invalid mode, please try again");
    
}
  // create board
  char boardmain[boardsizearr][boardsizearr];
  for (int i = 0; i < boardsizearr; i++) {
    for (int j = 0; j < boardsizearr; j++) {
      if (j % 2 == 0) {
        boardmain[i][j] = '-';
      } else {
        boardmain[i][j] = '|';
      }
      if (i % 2 == 0 && j % 2 == 0) {
        boardmain[i][j] = ' ';
      } else if (i % 2 != 0 && j % 2 != 0) {
        boardmain[i][j] = '+';
      }
    }

  }
  if (mode == 1) {
    printf("BOARD SIZE: %dx%d\n", boardsize, boardsize);
    round++;
    printf("Current Score: Player 1: %d  Player 2: %d\n", scorep1, scorep2);
    printf("Round: %d\n", round);
    printboard(boardmain, boardsizearr);
    //take input from player
  puts("Please input Player ones (X) move by using a location (ex. 3 2)");
  scanf("%d %d", &x, &y);
 
  boardmain[x][y] = 'X';
  printboard(boardmain, boardsizearr);

  }
  
}
}

// print board function
void printboard(char boardmain[100][100], int boardsizearr){
    // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
      }
    }
    printf("\n");
}