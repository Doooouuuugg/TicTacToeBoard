#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X) {
    return O;
  }
  
  return X;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece holder = this->getWinner();
  if ((holder != X) || (holder != O))
  {
    if ((row < 0 || row >= 3) || (column < 0 || column >= 3)) {
      return Invalid;
    }
  
    if (board[row][column] == Blank) {
      board[row][column] = turn;
      toggleTurn();
      return board[row][column];
    }
    
    if (board[row][column] == X || board[row][column] == O) {
      return board[row][column];
    }
  }
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if((row >= 0 && row < 3) && (column >= 0 && column < 3)) {
    return board[row][column];
  }

  else {
    return Invalid;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
   // Check for horizontal winner.
  for (int i = 0; i < 3; i++) {
    if (board[0][i] != Blank && board[0][i] == board[1][i] && board[1][i] == board[2][i])
      return board[0][i];
  }
  
  // Check for vertical winner.
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != Blank && board[i][0] == board[i][1] && board[i][1] == board[i][2])
      return board[i][0];
  }
  
  // Check for diagonal winner.
  if (board[1][1] != Blank && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return board[1][1];
  if (board[1][1] != Blank && board[2][0] == board[1][1] && board [1][1] == board[0][2])
    return board[1][1];
    
  // Check if the game is invalid.
  for (int i = 0; i < BOARDSIZE; i++)
    for (int ii = 0; ii < BOARDSIZE; ii++)
      if (board[i][ii] == Blank)
        return Invalid;
        
  return Blank;
}
