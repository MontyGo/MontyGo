
/*
   Copyright (c) 2015 Neil Babson and Gabe Stauth
   This source file is protected under the MIT License. 
   Please see the file LICENSE in the distribution for license terms.
*/

/*
   This file contains the header file for the gameBoard class which
   implements a Go board, allows legal moves, and remembers captures.
*/
#ifndef board_h
#define board_h

#include "stack.h"

struct moves_t
{
   bool win;
   int x[5];
   int y[5];
};


class gameBoard
{
   public:
      gameBoard();
      int move(int x, int y, int color);
      void draw();
      void undo();
      bool score(bool display);
      int tryMove(int firstx, int firsty, moves_t moves[]);
      int checkMoves();
      void removeDead();
   private:      
      int addGroup(int x, int y, int color);
      int checkNeighbor(int x, int y, int color);
      int checkLiberties(int x, int y, int color);
      void killGroup(int groupNum, int color);
      int numberGroup(int x, int y, int color);
      void resetFlags();
      void drawScored();
      void copy(gameBoard * to_copy);
      void displayGroup(int groupNum);

      stack history;           // Stack containing a history of moves played
      piece pieces[11][11];    // 9 x 9 board with an edge frame. 0=empty, 1=black,-1=white,3=edge
      int numString;           // The number that will be assigned  to the next string (connected group) formed
      bool koFlag;             // true if the next move is restricted due to ko
      int koMove[2];  // 0 = x, 1 = y
      int dead[2];   // 0 = black, 1=white
};


bool randomGame(gameBoard board, moves_t move, int color, bool display);
void dumbGame();

#endif
