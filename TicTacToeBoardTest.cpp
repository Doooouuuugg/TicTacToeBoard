/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// out of bounds test
TEST(TicTacToeBoardTest, pieceOutOfBounds)
{
	TicTacToeBoard obj;
	Piece outcome = Blank;
	outcome = obj.getPiece(100,100);
	ASSERT_EQ(outcome, Invalid);
}

// in bounds test
TEST(TicTacToeBoardTest, pieceInBounds)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.getPiece(2,2);
	ASSERT_EQ(outcome, Blank);
}

// Toggle turn test when X is placed
TEST(TicTacToeBoardTest, toggleTurnTestX)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.toggleTurn();
	ASSERT_EQ(outcome, O);
}

// Toggle turn test when O is placed
TEST(TicTacToeBoardTest, toggleTurnTestO)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.toggleTurn();
	ASSERT_FALSE(outcome == X);
}

// Place X in (0, 0)
TEST(TicTacToeBoardTest, placePieceX)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.placePiece(0,0);
	ASSERT_EQ(outcome, X);
}

// Place X and 0 in (0, 0)
TEST(TicTacToeBoardTest, placePieceTwoInSameSpot)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.placePiece(0,0);
	outcome = obj.placePiece(0,0);
	ASSERT_EQ(outcome, X);
}

// Try to place a piece out of bounds
TEST(TicTacToeBoardTest, placeOutOfBoundsPiece)
{
	TicTacToeBoard obj;
	Piece outcome;
	outcome = obj.placePiece(0,4);
	ASSERT_EQ(outcome, Invalid);
}

// when board is empy, there is no winner 
TEST(TicTacToeBoardTest, getEmptyBoardWinner) {
	TicTacToeBoard obj;
	ASSERT_TRUE(obj.getWinner() == Invalid);
}

// try getting a peice that is out of the board
TEST(TicTacToeBoardTest, GetOutOfRangePiece) {
	TicTacToeBoard obj;
	ASSERT_EQ(obj.getPiece(0, 4), Invalid);
	ASSERT_EQ(obj.getPiece(4, 0), Invalid);
}

// try getting a peice that is empty
TEST(TicTacToeBoardTest, GetEmptyPiece) {
	TicTacToeBoard obj;
	ASSERT_TRUE(obj.getPiece(0, 0) == Blank);
}

// get a winner that is horizontal 
TEST(TicTacToeBoardTest, GetHorizontalWinner) {
	TicTacToeBoard obj;
	Piece turn = obj.placePiece(2, 0);
	obj.placePiece(0, 0);
	obj.placePiece(2, 1);
	obj.placePiece(0, 1);
	obj.placePiece(2, 2);
	ASSERT_TRUE(obj.getWinner() == turn);
}

// get a winner that is vertical
TEST(TicTacToeBoard, GetVerticalWinner) {
	TicTacToeBoard obj;
	Piece turn = obj.placePiece(0, 2);
	obj.placePiece(0, 0);
	obj.placePiece(1, 2);
	obj.placePiece(2, 0);
	obj.placePiece(2, 2);
	ASSERT_TRUE(obj.getWinner() == turn);
}

// get a winner that is diagonal
TEST(TicTacToeBoard, GetWinnerDiagonal) {
	TicTacToeBoard obj;
	Piece turn = obj.placePiece(0, 0);
	obj.placePiece(0, 1);
	obj.placePiece(1, 1);
	obj.placePiece(2, 0);
	obj.placePiece(2, 2);
	ASSERT_TRUE(obj.getWinner() == turn);
}

// get a winner that is diagonal in the other direction 
TEST(TicTacToeBoard, GetWinnerBackwardsDiagonal) {
	TicTacToeBoard obj;
	Piece turn = obj.placePiece(2, 0);
	obj.placePiece(0, 1);
	obj.placePiece(1, 1);
	obj.placePiece(1, 0);
	obj.placePiece(0, 2);
	ASSERT_EQ(obj.getWinner(), turn);
}

// try getting a winner before there are enough peices for there to be a win
TEST(TicTacToeBoard, GetWinnerWithoutPieces) {
	TicTacToeBoard obj;
	obj.placePiece(1, 1);
	ASSERT_TRUE(obj.getWinner() == Invalid);
}

// try getting a winner when its a cats game, doesn't work right right now
TEST(TicTacToeBoardTest, GetWinnerCats) {
	TicTacToeBoard obj;
	obj.placePiece(0, 0);
	obj.placePiece(1, 0);
	obj.placePiece(0, 1);
	obj.placePiece(1, 1);
	obj.placePiece(1, 2);
	obj.placePiece(0, 2);
	obj.placePiece(2, 0);
	obj.placePiece(2, 1);
	obj.placePiece(2, 2);
	ASSERT_EQ(obj.getWinner(), Blank);
}
