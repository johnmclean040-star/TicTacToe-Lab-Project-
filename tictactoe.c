#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int player1move(int boardsizearr, char boardmain[boardsizearr][boardsizearr]) {
    int x=0,y=0;
    printf("\n");
puts("Player 1 Input move via coordinates(space in between)");
        scanf("%d %d", &x, &y);
        int x1=x-2, y1=y-2;
        x=x+x1;
        y=y+y1;
        if (boardmain[x][y] == 'X' || boardmain[x][y] == 'O') {
          puts("Invalid move, coordinate already taken, please try again");
          return player1move(boardsizearr, boardmain);
        }
        boardmain[x][y] = 'X';
        // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
    }

int player2move(int boardsizearr, char boardmain[boardsizearr][boardsizearr]) {
    int x=0,y=0;
    printf("\n");
    puts("Player 2 Input move via coordinates(space in between)");
        scanf("%d %d", &x, &y);
        int x1=x-2, y1=y-2;
        x=x+x1;
        y=y+y1;
        if (boardmain[x][y] == 'X' || boardmain[x][y] == 'O') {
          puts("Invalid move, coordinate already taken, please try again");
          return player2move(boardsizearr, boardmain);
        }
        boardmain[x][y] = 'O';
        // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
    }

int roundwinchecker(int boardsizearr, char boardmain[boardsizearr][boardsizearr], int *game) {
  // check rows for win
  for (int i = 0; i < boardsizearr; i += 2) {
    int countX = 0;
    int countO = 0;
    for (int j = 0; j < boardsizearr; j += 2) {
      if (boardmain[i][j] == 'X') {
        countX++;
      } else if (boardmain[i][j] == 'O') {
        countO++;
      }
    }
    if (countX == (boardsizearr + 1) / 2) {
      printf("\n");
      puts("Player 1 Wins!");
      *game=2;
      return 1;
    } else if (countO == (boardsizearr + 1) / 2 ) {
      printf("\n");
      puts("Player 2 Wins!");
      *game=3;
      return 2;
    }
  }
  // check columns for win
  for (int j = 0; j < boardsizearr; j += 2) {
    int countX = 0;
    int countO = 0;
    for (int i = 0; i < boardsizearr; i += 2) {
      if (boardmain[i][j] == 'X') {
        countX++;
      } else if (boardmain[i][j] == 'O') {
        countO++;
      }
    }
    if (countX == (boardsizearr + 1) / 2) {
      puts("Player 1 Wins!");
      return 1;
    } else if (countO == (boardsizearr + 1) / 2) {
      puts("Player 2 Wins!");
      return 2;
    }
  }
  return 0;
}


int main() {
  int boardsize = 1;
  int scorep1=0, scorep2=0;
  int mode = 0, round=1;
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
  start:
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
  game= 0;
  while(mode == 1 && game == 0) {
    game=1;
    printf("BOARD SIZE: %dx%d\n", boardsize, boardsize);
    // print board state
    for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
    }
    if(game == 1){
      while(roundwinchecker(boardsizearr, boardmain, &game) == 0){
        printf("\nRound: %d, Score: Player 1: %d, Player 2: %d\n", round, scorep1, scorep2);
        roundwinchecker(boardsizearr, boardmain, &game);
        player1move(boardsizearr, boardmain);
        // add player 2 move function here
        roundwinchecker(boardsizearr, boardmain, &game);
        if(game == 1){
        player2move(boardsizearr, boardmain);
        }
      }
  }
   if(game == 2){
        scorep1++;
        round++;
        goto start;
      }
   else if(game ==3){
        scorep2++;
        round++;
        goto start;
      }


}

