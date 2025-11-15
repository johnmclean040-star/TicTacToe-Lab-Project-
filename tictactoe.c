#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main() {
  int boardsize = 1;
  int mode = 0;
  int game = 0;
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
  int x=0,y=0;
  if(mode == 1) {
    printf("BOARD SIZE: %dx%d\n", boardsize, boardsize);
    game = 1;
    // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
    }
    if(game == 1){
        puts("Player 1 Input move via coordinates");
        scanf("%d %d", &x, &y);
        int x1=x-2, y1=y-2;
        x=x+x1;
        y=y+y1;
        boardmain[x][y] = 'X';
        // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
    }
    }

