//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Helmet.h"

    TEST(HelmetCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
        EXPECT_THROW(Helmet::createHelmet("DamageBonus"),std::invalid_argument);
        EXPECT_THROW(Helmet::createHelmet("Strength"),std::invalid_argument);
    }
    TEST(HelmetCreation, GivenValidArgumentShouldNotThrow) {
        EXPECT_NO_THROW(Helmet::createHelmet("ArmorClass"));
        EXPECT_NO_THROW(Helmet::createHelmet("Intelligence"));
}