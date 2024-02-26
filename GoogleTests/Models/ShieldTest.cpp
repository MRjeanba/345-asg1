//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Shield.h"

TEST(ShieldCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Shield::createShield("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Shield::createShield("AHHHHHHHH"),std::invalid_argument);
}
TEST(ShieldCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Shield::createShield("ArmorClass"));
}