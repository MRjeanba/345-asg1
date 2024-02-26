//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Dice.h"

/**
 * Set up the subject under test and tear down the subject after the test
 */
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

/**
 * Test the correctness of the expression given as parameter
 */
TEST_F(DiceClassTest, isValidExpressionInvalidExpression)
{
    EXPECT_FALSE(dice->isValidExpression("InvalidExpression"));
};

/**
 * Test the correctness of the expression given as parameter
 */
TEST_F(DiceClassTest, isValidExpressionNoPlusOperator)
{
    EXPECT_FALSE(dice->isValidExpression("3d6 4"));
};

/**
 * Test the correctness of the expression given as parameter
 */
TEST_F(DiceClassTest, isValidExpressionInvalidFormat)
{
    EXPECT_FALSE(dice->isValidExpression("3d6 b"));
};

/**
 * Test the correctness of the expression given as parameter
 */
TEST_F(DiceClassTest, IsValidExpressionEmptyString)
{

    EXPECT_FALSE(dice->isValidExpression(""));
};

/**
 * Test the correctness of the expression given as parameter
 */
TEST_F(DiceClassTest, IsValidExpressionNoValidTypeDice)
{
    EXPECT_FALSE(dice->isValidExpression("4d40+9"));
};