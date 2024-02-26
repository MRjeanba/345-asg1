//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Belt.h"

TEST(BeltCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Belt::createBelt("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Belt::createBelt("AHHHHHHHH"),std::invalid_argument);
}
TEST(BeltCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Belt::createBelt("Constitution"));
    EXPECT_NO_THROW(Belt::createBelt("Strength"));
}