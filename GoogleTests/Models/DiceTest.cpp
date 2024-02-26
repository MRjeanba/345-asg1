//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Dice.h"

class DiceClassTest : public ::testing::Test
{
protected:
    // Test setup, always called when running test
    void setUp()
    {
        dice = new Dice();
    }

    // Test Cleanup
    void tearDown()
    {
        delete dice;
    }

    Dice *dice;
};

//// Test for rolling the dice
//TEST_F(DiceClassTest, RollDiceValidResult)
//{
//    // Test case for a valid expression
//    int result = dice->rollDice("2d6 + 3");
//
//    // Assuming the result should be between 5 and 15 (inclusive)
//    EXPECT_GE(result, 5);  // Greater than or equal to 5
//    EXPECT_LE(result, 15); // Less than or equal to 15
//}

// Tests to check if it returns true or false depending on the expression
//TEST_F(DiceClassTest, isValidExpressionValidExpression)
//{
//    EXPECT_TRUE(dice->isValidExpression("2d6 + 3"));
//};
TEST_F(DiceClassTest, isValidExpressionInvalidExpression)
{
    EXPECT_FALSE(dice->isValidExpression("InvalidExpression"));
};
TEST_F(DiceClassTest, isValidExpressionNoPlusOperator)
{
    EXPECT_FALSE(dice->isValidExpression("3d6 4"));
};
TEST_F(DiceClassTest, isValidExpressionInvalidFormat)
{
    EXPECT_FALSE(dice->isValidExpression("3d6 b"));
};
TEST_F(DiceClassTest, IsValidExpressionEmptyString)
{

    EXPECT_FALSE(dice->isValidExpression(""));
};
TEST_F(DiceClassTest, IsValidExpressionNoValidTypeDice)
{
    EXPECT_FALSE(dice->isValidExpression("4d40+9"));
};