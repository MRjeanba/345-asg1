#include <gtest/gtest.h>
#include "../../Models/fighter.h"

//// todo : generateabilities(138)
//
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

TEST_F(FighterTest, GenerateRandomNumberInRange)
{
    int num = fighterObj->generateRandomNum();
    // Checking that number is in correct range
    EXPECT_GE(num, 1);
    EXPECT_LE(num, 20);
}

//TEST_F(FighterTest, SetLevelInRange)
//{
//    // Creating fighter with level in range 0->5
//    fighterObj->setLevel(3);
//    EXPECT_EQ(fighterObj->getLevel(), 2);
//
//    // Ceating fighter with level below accepted range
//    fighterObj->setLevel(-2);
//    EXPECT_EQ(fighterObj->getLevel(), 1); // Set fighter to level 1 if out of bounds
//
//    // Ceating fighter with level above accepted range
//    fighterObj->setLevel(20);
//    EXPECT_EQ(fighterObj->getLevel(), 1); // Set fighter to level 1 if out of bounds
//}
//
//TEST_F(FighterTest, SettingCorrectHp)
//{
//    // Test for a fighter that is level 1
//    fighterObj->setHp(1);
//    EXPECT_EQ(fighterObj->getHp(), 100);
//
//    // Test for a fighter that is level 4
//    fighterObj->setHp(4);
//    EXPECT_EQ(fighterObj->getHp(), 250);
//}
//
////TEST_F(FighterTest, SetCorrrectItem)
////{
////    // Passing 0 to setItem() as a mock value, as if it was the value randomly generated (setItem() does not take params)
////    fighterObj->setItem(0);
////    EXPECT_EQ(fighterObj->getItem(), "armor");
////
////    fighterObj->setItem(2);
////    EXPECT_EQ(fighterObj->getItem(), "weapon");
////}
//
////TEST_F(FighterTest, GenerateAbilities)
////{
////    // Set up mock random number generator
////    MockRandomNumberGenerator mockRandomNumberGenerator;
////
////    // Set expected return values for generateRandomNum calls
////    int strengthValue = 15;
////    int dexterityValue = 12;
////    int constitutionValue = 14;
////    EXPECT_CALL(mockRandomNumberGenerator, generateRandomNum())
////            .WillOnce(::testing::Return(strengthValue))
////            .WillOnce(::testing::Return(dexterityValue))
////            .WillOnce(::testing::Return(constitutionValue));
////
////    // Replace the fighter's generateRandomNum method with the mock
////    fighterObj.generateRandomNum() = std::bind(&MockRandomNumberGenerator::generateRandomNum, &mockRandomNumberGenerator);
////
////    // Call the method under test
////    fighterObj.generateAbilities();
////
////    // Check if the abilities are set correctly
////    EXPECT_EQ(fighterObj.getStrength(), strengthValue);
////    EXPECT_EQ(fighterObj.getDexterity(), dexterityValue);
////    EXPECT_EQ(fighterObj.getConstitution(), constitutionValue);
////}
//
TEST_F(FighterTest, CalculateModifier)
{
    EXPECT_EQ(fighterObj->calculateModifier(10), 0); // Ability score 10 should result in modifier 0
    EXPECT_EQ(fighterObj->calculateModifier(15), 2); // Ability score 15 should result in modifier 2
    EXPECT_EQ(fighterObj->calculateModifier(8), -1); // Ability score 8 should result in modifier -1
}
//
//TEST_F(FighterTest, CalculateHitPoints)
//{
//    // Set up fighter with known constitution and level
//    int constitution = 15; // Example constitution score (15)
//    int level = 3; // Example level (3)
//    fighterObj->setConstitution(constitution);
//    fighterObj->setLevel(level);
//
//    // Calculate expected hit points (value used to verify correctness of method)
//    int expectedHitPoints = (constitution - 10) / 2 * level;
//
//    // Call the method under test
//    fighterObj->calculateHitPoints();
//
//    // Check if the hit points are set correctly
//    EXPECT_EQ(fighterObj->getHitPoints(), expectedHitPoints);
//}
//
//TEST_F(FighterTest, CalculateArmorClass)
//{
//    // Set up fighter with known dexterity
//    int dexterity = 15; // Example dexterity score (15)
//    fighterObj->setDexterity(dexterity);
//
//    // Calculate expected armor class (value used to verify correctness of method)
//    int expectedArmorClass = (dexterity - 10) / 2 + 10;
//
//    // Call the method under test
//    fighterObj->calculateArmorClass();
//
//    // Check if the armor class is set correctly
//    EXPECT_EQ(fighterObj->getArmorClass(), expectedArmorClass);
//}
//
//TEST_F(FighterTest, CalculateAttackBonus)
//{
//    int strength = 16;
//    int level = 5;
//    fighterObj->setStrength(strength);
//    fighterObj->setLevel(5);
//    int expectedAttackBonus = (strength - 10) / 2 + level;
//    fighterObj->calculateAttackBonus();
//    EXPECT_EQ(fighterObj->getAttackBonus(), expectedAttackBonus);
//}
//
//TEST_F(FighterTest, CalculateDamageBonus)
//{
//    int strength = 18;
//    fighterObj->setStrength(strength);
//    int expectedDamageBonus = (strength - 10) / 2;
//    fighterObj->calculateDamageBonus();
//    EXPECT_EQ(fighterObj->getDamageBonus(), expectedDamageBonus);
//}
