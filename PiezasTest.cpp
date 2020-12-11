/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, placePieceHappy)
{
	Piezas pb;
  pb.dropPiece(0);
  ASSERT_EQ(pb.pieceAt(0,0), X);
}

TEST(PiezasTest, placePiecePlayer2)
{
	Piezas pb;
  pb.dropPiece(0);
  pb.dropPiece(0);
  ASSERT_EQ(pb.pieceAt(1,0), O);
}

TEST(PiezasTest, placePieceTopRow)
{
	Piezas pb;
  pb.dropPiece(0);
  pb.dropPiece(0);
  pb.dropPiece(0);
  ASSERT_EQ(pb.pieceAt(2,0), X);
}

TEST(PiezasTest, placePieceFull)
{
	Piezas pb;
  pb.dropPiece(0);
  pb.dropPiece(0);
  pb.dropPiece(0);
  pb.dropPiece(0);
  pb.dropPiece(1);
  ASSERT_EQ(pb.pieceAt(0,1), X);
}

TEST(PiezasTest, InvalidPlace)
{
  Piezas pb;
	ASSERT_EQ(pb.pieceAt(-1,1), Invalid);
}

TEST(PiezasTest, validPlace)
{
  Piezas pb;
	ASSERT_EQ(pb.pieceAt(1,1), Blank);
}


TEST(PiezasTest, gameStateNotFinished)
{
	Piezas pb;
  ASSERT_EQ(pb.gameState(), Invalid);
}

TEST(PiezasTest, gameStateTie)
{
	Piezas pb;
  pb.dropPiece(0);
  pb.dropPiece(1);
  pb.dropPiece(0);
  pb.dropPiece(1);
  pb.dropPiece(0);
  pb.dropPiece(1);
  pb.dropPiece(2);
  pb.dropPiece(3);
  pb.dropPiece(2);
  pb.dropPiece(3);
  pb.dropPiece(2);
  pb.dropPiece(3);
  ASSERT_EQ(pb.gameState(), Blank);
}

TEST(PiezasTest, gameStateXWins)
{
	Piezas pb;
  pb.dropPiece(0);
	pb.dropPiece(0);
	pb.dropPiece(1);
	pb.dropPiece(0);
	pb.dropPiece(2);
	pb.dropPiece(1);
	pb.dropPiece(2);
	pb.dropPiece(1);
	pb.dropPiece(2);
	pb.dropPiece(3);
	pb.dropPiece(3);
	pb.dropPiece(3);
  ASSERT_EQ(pb.gameState(), X);
}

TEST(PiezasTest, gameStateOWins)
{
	Piezas pb;
	pb.dropPiece(12);
	pb.dropPiece(0);
	pb.dropPiece(0);
	pb.dropPiece(1);
	pb.dropPiece(0);
	pb.dropPiece(2);
	pb.dropPiece(1);
	pb.dropPiece(2);
	pb.dropPiece(1);
	pb.dropPiece(2);
	pb.dropPiece(3);
	pb.dropPiece(3);
	pb.dropPiece(3);
  ASSERT_EQ(pb.gameState(), O);
}
