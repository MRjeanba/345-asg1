//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Shield.h"

/**
 * This test verify that the ShieldCreation behaves correctly
 * In this case we expect that with a wrong enchantmentType the creation should throw an error
 */
TEST(ShieldCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Shield::createShield("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Shield::createShield("AHHHHHHHH"),std::invalid_argument);
}

/**
 * This test verify that the ShieldCreation behaves correctly
 * In this specific case, we verify that no errors are thrown during the Shield class creation
 */
TEST(ShieldCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Shield::createShield("ArmorClass"));
}