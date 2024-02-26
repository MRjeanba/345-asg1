//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Armor.h"

    TEST(ArmorCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
        EXPECT_THROW(Armor::createArmor("DamageBonus"),std::invalid_argument);
        EXPECT_THROW(Armor::createArmor("AHHHHHHHH"),std::invalid_argument);
    }
    TEST(ArmorCreation, GivenValidArgumentShouldNotThrow) {
            EXPECT_NO_THROW(Armor::createArmor("ArmorClass"));
    }