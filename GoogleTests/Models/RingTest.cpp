//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Ring.h"

    TEST(RingCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
        EXPECT_THROW(Ring::createRing("DamageBonus"),std::invalid_argument);
        EXPECT_THROW(Ring::createRing("AHHHHHHHH"),std::invalid_argument);
    }
TEST(RingCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Ring::createRing("ArmorClass"));
    EXPECT_NO_THROW(Ring::createRing("Wisdom"));
}