//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Ring.h"

/**
 * This test verify that the RingCreation behaves correctly
 * In this case we expect that with a wrong enchantmentType the creation should throw an error
 */
TEST(RingCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Ring::createRing("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Ring::createRing("AHHHHHHHH"),std::invalid_argument);
}

/**
 * This test verify that the RingCreation behaves correctly
 * In this specific case, we verify that no errors are thrown during the Ring class creation
 */
TEST(RingCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Ring::createRing("ArmorClass"));
    EXPECT_NO_THROW(Ring::createRing("Wisdom"));
}