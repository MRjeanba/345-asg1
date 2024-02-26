//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Boots.h"

TEST(BootsCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Boots::createBoots("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Boots::createBoots("AHHHHHHHH"),std::invalid_argument);
}
TEST(BootsCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Boots::createBoots("ArmorClass"));
    EXPECT_NO_THROW(Boots::createBoots("Dexterity"));
}