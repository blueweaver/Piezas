#include "Piezas.h"
#include <vector>
#include <iostream>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
  for(int i=0; i<BOARD_ROWS; i++) {
    for(int j=0; j<BOARD_COLS; j++) {
      board[i][j] = Blank;
    }
    }
  turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for (int i = 0; i < BOARD_ROWS; i++)
    {
        for (int j = 0; j < BOARD_COLS; j++)
        {
            board[i][j] = Blank;
        }
    }
    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
  int itor = 0;
  while(itor < 4) {
    if(board[itor][column] == Blank) {
      board[itor][column] = turn;
    }
    itor++;
  }
  if(turn == X) {
    turn = O;
  } else {
    turn = X;
  }
    return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
  if(row > 2 || column > 3 || row < 0 || column < 0) {
    return Invalid;
  } else {
    return board[row][column];
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
  for(int i=0; i<BOARD_ROWS; i++) {
    for(int j=0; j<BOARD_COLS; j++) {
      if(board[i][j] == Blank) {
        return Invalid;
      }
    }
    }
    int currentXMax = 0;
    int currentX = 0;
    int currentOMax = 0;
    int currentO = 0;
    int itor = 1;
    for(int i=0; i<BOARD_ROWS; i++) {
      for(int j=0; j<BOARD_COLS; j++) {
        if(board[i][j] == X) {
          currentX++;
          while(itor != 4) {
            if(board[i + itor][j] == X) {
              currentX++;
              itor++;
            } else {
              itor = 4;
            }
          }
          itor = 1;
        } else if(board[i][j] == O) {
          currentO++;
          while(itor != 4) {
            if(board[i + itor][j] == X) {
              currentX++;
              itor++;
            } else {
              itor = 4;
            }
        }
      }
      if(currentX > currentXMax) {
        currentXMax = currentX;
      }
      if (currentO > currentOMax) {
        currentOMax = currentO;
      }
      currentX = 0;
      currentO = 0;
      }
    if(currentXMax > currentOMax) {
      return X;
    } else if (currentXMax < currentOMax) {
      return O;
    } else {
      return Blank;
    }
}
return Blank;
}
