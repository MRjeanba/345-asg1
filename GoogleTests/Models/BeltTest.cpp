//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Belt.h"

/**
 * This test verify that the BeltCreation behaves correctly
 * In this case we expect that with a wrong enchantmentType the creation should throw an error
 */
TEST(BeltCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Belt::createBelt("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Belt::createBelt("AHHHHHHHH"),std::invalid_argument);
}

/**
 * This test verify that the BeltCreation behaves correctly
 * In this specific case, we verify that no errors are thrown during the Belt class creation
 */
TEST(BeltCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Belt::createBelt("Constitution"));
    EXPECT_NO_THROW(Belt::createBelt("Strength"));
}