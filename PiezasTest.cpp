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

TEST(PiezasTest, firstDrop) {
    Piezas pie;
    pie.dropPiece(2);
    ASSERT_EQ(pie.dropPiece(1), O);
}

TEST(PiezasTest, sameDrop) {
    Piezas pie;
    //pie.dropPiece(1);
    ASSERT_EQ(pie.dropPiece(1), X);
}

TEST(PiezasTest, reset) {
    Piezas pie;
    pie.dropPiece(1);
    pie.reset();
    ASSERT_EQ(pie.pieceAt(0,1), Blank);
}

TEST(PiezasTest, dropOut1) {
    Piezas pie;
    ASSERT_EQ(pie.dropPiece(4), Invalid);
}

TEST(PiezasTest, dropOut2) {
    Piezas pie;
    ASSERT_EQ(pie.dropPiece(-1), Invalid);
}

TEST(PiezasTest, topDrop) {
    Piezas pie;
    pie.dropPiece(3);
    pie.dropPiece(3);
    pie.dropPiece(2);
    pie.dropPiece(3);
    ASSERT_EQ(pie.dropPiece(3), Blank);
}
 TEST(PiezasTest, topDrop2) {
    Piezas pie;
    pie.dropPiece(0);
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(0);
    ASSERT_EQ(pie.dropPiece(0), Blank);
}

TEST(PiezasTest, pieceOut) {
    Piezas pie;
    ASSERT_EQ(pie.pieceAt(7,0), Invalid);
}

TEST(PiezasTest, pieceOut2) {
    Piezas pie;
    ASSERT_EQ(pie.pieceAt(1,7), Invalid);
}

TEST(PiezasTest, state) {
    Piezas pie;
    ASSERT_EQ(pie.gameState(), Invalid);
}
TEST(PiezasTest, state2) {
    Piezas pie;
    pie.dropPiece(0);
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(2);
    pie.dropPiece(3);
    ASSERT_EQ(pie.gameState(), Invalid);
}

TEST(PiezasTest, state3) {
    Piezas pie;
    pie.dropPiece(0);
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(2);
    pie.dropPiece(3);
    pie.dropPiece(0);
    pie.dropPiece(0);
    pie.dropPiece(0);
    ASSERT_EQ(pie.gameState(), Invalid);
}

TEST(PiezasTest, tie1) {
    Piezas pie;
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(0);
    pie.dropPiece(1);
    ASSERT_EQ(pie.gameState(), Invalid);
}

TEST(PiezasTest, tie2) {
    Piezas pie;
    pie.dropPiece(0);
    pie.dropPiece(0);
    pie.dropPiece(1);
    pie.dropPiece(1);
    pie.dropPiece(2);
    pie.dropPiece(2);
    ASSERT_EQ(pie.gameState(), Invalid);
}

/*     
 *  OOXX
 *  OXOX
 *  XOOX
 */

TEST(PiezasTest, win1) {
    Piezas pie;
    pie.dropPiece(3); //X
    pie.dropPiece(2); //O
    pie.dropPiece(3); //X
    pie.dropPiece(2); //O
    pie.dropPiece(3); //X
    pie.dropPiece(1); //O
    pie.dropPiece(1); //X
    pie.dropPiece(1); //O
    pie.dropPiece(0); //X
    pie.dropPiece(1); //O
    pie.dropPiece(2); //X
    pie.dropPiece(1); //O
    pie.dropPiece(0); //X
    pie.dropPiece(1);
    pie.dropPiece(0);

    ASSERT_EQ(pie.gameState(), X);
}

TEST(PiezasTest, win2) {
    Piezas pie;
    pie.dropPiece(3);
    pie.dropPiece(3);
    pie.dropPiece(3);
    pie.dropPiece(0);
    pie.dropPiece(3);
    pie.dropPiece(0);
    pie.dropPiece(3);
    pie.dropPiece(0);
    pie.dropPiece(3);
    pie.dropPiece(1);
    pie.dropPiece(3);
    pie.dropPiece(1);
    pie.dropPiece(3);
    pie.dropPiece(1);
    pie.dropPiece(3);
    pie.dropPiece(2);
    pie.dropPiece(3);
    pie.dropPiece(2);
    pie.dropPiece(3);
    pie.dropPiece(2);

    ASSERT_EQ(pie.gameState(), O);
}
