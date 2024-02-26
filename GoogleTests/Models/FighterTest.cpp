#include <gtest/gtest.h>
#include "../../Models/fighter.h"

/**
 * Set up the subject under test and tear down the subject after the test
 */
class FighterTest : public::testing::Test
{
protected:
// Test setup, always called when running test
void setUp()
{
fighterObj = new fighter(1);
}

// Test Cleanup
void tearDown()
{
delete fighterObj;
}

fighter* fighterObj{};
};

/**
 * Test tje random number generation in Fighter class
 */
TEST_F(FighterTest, GenerateRandomNumberInRange)
{
    int num = fighterObj->generateRandomNum();
    // Checking that number is in correct range
    EXPECT_GE(num, 1);
    EXPECT_LE(num, 20);
}
/**
 * Verify that the Ability score behaves correctly
 */
TEST_F(FighterTest, CalculateModifier)
{
    EXPECT_EQ(fighterObj->calculateModifier(10), 0); // Ability score 10 should result in modifier 0
    EXPECT_EQ(fighterObj->calculateModifier(15), 2); // Ability score 15 should result in modifier 2
    EXPECT_EQ(fighterObj->calculateModifier(8), -1); // Ability score 8 should result in modifier -1
}
