#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//functions
int createBoard(int boardsizearr, char boardmain[boardsizearr][boardsizearr]) {
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
  for (int i = 0; i < boardsizearr; i++) {
      printf("\n");
      for (int j = 0; j < boardsizearr; j++) {
        printf("%c", boardmain[i][j]);
        }
      }
}

int player1move(int boardsizearr, char boardmain[boardsizearr][boardsizearr]) {
    int x=0,y=0;
    printf("\n");
puts("Player 1 Input move via coordinates(space in between)");
        scanf("%d %d", &x, &y);
        int x1=x-2, y1=y-2;
        x=x+x1;
        y=y+y1;
        if (boardmain[x][y] == 'X' || boardmain[x][y] == 'O' || x > boardsizearr || y > boardsizearr || x < 0 || y < 0) {
          puts("Invalid move coordinate, please try again");
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
        if (boardmain[x][y] == 'X' || boardmain[x][y] == 'O' || x > boardsizearr || y > boardsizearr || x < 0 || y < 0) {
          puts("Invalid move coordinate, please try again");
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
    
    
    
    
    
int playeraimove(int boardsizearr, char boardmain[boardsizearr][boardsizearr]) {
    int x=0,y=0;
    int movemade=0;
    printf("\n");
    puts("AI is making a move...");
    //win ai rows
  for (int i = 0; i < boardsizearr; i += 2) {
     int countX = 0;
     int countO = 0;
     int wini = 0;
     int winj = 0;
     for (int j = 0; j < boardsizearr; j += 2) {
       if (boardmain[i][j] == 'O') {
         countO++;
       } else if (boardmain[i][j] == ' ') {
         wini = i;
         winj = j;
       }
     }
     if (countO == (boardsizearr) / 2) {
     if(movemade == 0){
       boardmain[wini][winj] = 'O';
     movemade=1;
     }
     } 
   }
   //win ai columns
     for (int j = 0; j < boardsizearr; j += 2) {
     int countX = 0;
     int countO = 0;
     int wini = 0;
     int winj = 0;
     for (int i = 0; i < boardsizearr; i += 2) {
       if (boardmain[i][j] == 'O') {
         countO++;
       } else if (boardmain[i][j] == ' ') {
         wini = i;
         winj = j;
       }
     }
     if (countO == (boardsizearr) / 2) {
       if(movemade == 0){
       boardmain[wini][winj] = 'O';
       movemade=1;
       }
      
     }
   }
    //counter rows
for (int i = 0; i < boardsizearr; i += 2) {
    int countX = 0;
    int countO = 0;
    int safei = 0;
    int safej = 0;
    for (int j = 0; j < boardsizearr; j += 2) {
      if (boardmain[i][j] == 'X') {
        countX++;
      } else if (boardmain[i][j] == ' ') {
        safei = i;
        safej = j;
      }
    }
    if (countX == (boardsizearr) / 2) {
    boardmain[safei][safej] = 'O';
    movemade=1;
    } 
  }
  //counter columns
    for (int j = 0; j < boardsizearr; j += 2) {
    int countX = 0;
    int countO = 0;
    int safei = 0;
    int safej = 0;
    for (int i = 0; i < boardsizearr; i += 2) {
      if (boardmain[i][j] == 'X') {
        countX++;
      } else if (boardmain[i][j] == ' ') {
        safei = i;
        safej = j;
      }
    }
    if (countX == (boardsizearr) / 2) {
      boardmain[safei][safej] = 'O';
      movemade=1;
     
    }
  }
    //random moves if no counter needed
    while(movemade == 0){
      for (int i = 0; i < boardsizearr; i++) {
    for (int j = 0; j < boardsizearr; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
       if (movemade == 0 && boardmain[i][j] == ' ') {
        boardmain[i][j] = 'O';
        movemade=1;
      
       }
      }
    }
  }
    }
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
  // check diagonals for win
  int i = 0;
  int j = 0;


  int countX = 0;
  int countO = 0;
  while(i < boardsizearr && j < boardsizearr) {


    if (boardmain[i][j] == 'X') {
        countX++;
      } else if (boardmain[i][j] == 'O') {
        countO++;
      }


    i = i + 2;
    j = j + 2;
 
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
  reset_game:
  int boardsize = 1;
  int scorep1=0, scorep2=0;
  int mode = 0, round=1;
  int game = 0, tie=0;
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
if(mode ==1){
  // create board
  char boardmain[boardsizearr][boardsizearr];
  int x=0,y=0;
  game= 0;
  while(1) {
    game = 1;
    tie= boardsize * boardsize;
    printf("BOARD SIZE: %dx%d\n", boardsize, boardsize);
    // print board state
    createBoard(boardsizearr, boardmain);
    if(game == 1){
      while(roundwinchecker(boardsizearr, boardmain, &game) == 0 && round < 4){
        printf("\nRound: %d, Score: Player 1: %d, Player 2: %d\n", round, scorep1, scorep2);
        player1move(boardsizearr, boardmain);
        roundwinchecker(boardsizearr, boardmain, &game);
         if(tie>0){
          tie--;
        }
        if(tie == 0){
          puts("It's a tie!");
          round++;
          printf("\n");
          break;
        }
        if (roundwinchecker(boardsizearr, boardmain, &game) != 0){
          break;
        }
        player2move(boardsizearr, boardmain);
        roundwinchecker(boardsizearr, boardmain, &game);
         if(tie>0){
          tie--;
        }
        if(tie == 0){
          puts("It's a tie!");
          round++;
          printf("\n");
          break;
      }
     
  }
   if(roundwinchecker(boardsizearr, boardmain, &game) == 1){
        ++scorep1;
        ++round;
        printf("\n");
        char boardmain[boardsizearr][boardsizearr];
        int x=0,y=0;
      }
   else if(roundwinchecker(boardsizearr, boardmain, &game) ==2){
        scorep2++;
        round++;
        printf("\n");
        char boardmain[boardsizearr][boardsizearr];
        int x=0,y=0;
      }
      if (round > 3){
        puts("Game Over");
        printf("Final Score: Player 1: %d, Player 2: %d\n", scorep1, scorep2);
        puts("Would you like to play again? (1 for yes, 2 for ai)");
        scanf("%d", &mode);
        if(mode == 1){
            boardsize = 1;
            scorep1=0;
            scorep2=0;
            round=1;
            game=0;
            goto reset_game;
        }
        else if(mode == 2){
          
         break;
        }
      }


}
    }
  }






    if(mode == 2){
     // create board
  char boardmain[boardsizearr][boardsizearr];
  int x=0,y=0;
  game= 0;
  while(2) {
    game = 1;
    tie= boardsize * boardsize;
    printf("BOARD SIZE: %dx%d\n", boardsize, boardsize);
    // print board state
    createBoard(boardsizearr, boardmain);
    if(game == 1){
      while(roundwinchecker(boardsizearr, boardmain, &game) == 0 && round < 4){
        printf("\nRound: %d, Score: Player: %d, Tic-tac-toe Bot: %d\n", round, scorep1, scorep2);
        player1move(boardsizearr, boardmain);
        roundwinchecker(boardsizearr, boardmain, &game);
         if(tie>0){
          tie--;
        }
        if(tie == 0){
          puts("It's a tie!");
          round++;
          printf("\n");
          break;
        }
        if (roundwinchecker(boardsizearr, boardmain, &game) != 0){
          break;
        }
        playeraimove(boardsizearr, boardmain);
        roundwinchecker(boardsizearr, boardmain, &game);
         if(tie>0){
          tie--;
        }
        if(tie == 0){
          puts("It's a tie!");
          round++;
          printf("\n");
          break;
      }
     
  }
   if(roundwinchecker(boardsizearr, boardmain, &game) == 1){
        ++scorep1;
        ++round;
        printf("\n");
        char boardmain[boardsizearr][boardsizearr];
        int x=0,y=0;
      }
   else if(roundwinchecker(boardsizearr, boardmain, &game) ==2){
        scorep2++;
        round++;
        printf("\n");
        char boardmain[boardsizearr][boardsizearr];
        int x=0,y=0;
      }
      if (round > 3){
        puts("Game Over");
        printf("Final Score: Player: %d, Tic-tac-toe Bot: %d\n", scorep1, scorep2);
        puts("Would you like to play again? (1 for yes, 2 for to exit)");
        scanf("%d", &mode);
        if(mode == 1){
            boardsize = 1;
            scorep1=0;
            scorep2=0;
            round=1;
            game=0;
            goto reset_game;
        }
        else if(mode == 2){
          
         return 0;
        }
      }


}
    }
  }
  }


