//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Helmet.h"

/**
     * This test verify that the HelmetCreation behaves correctly
     * In this case we expect that with a wrong enchantmentType the creation should throw an error
     */
    TEST(HelmetCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
        EXPECT_THROW(Helmet::createHelmet("DamageBonus"),std::invalid_argument);
        EXPECT_THROW(Helmet::createHelmet("Strength"),std::invalid_argument);
    }

    /**
     * This test verify that the BeltCreation behaves correctly
     * In this specific case, we verify that no errors are thrown during the Helmet class creation
     */
    TEST(HelmetCreation, GivenValidArgumentShouldNotThrow) {
        EXPECT_NO_THROW(Helmet::createHelmet("ArmorClass"));
        EXPECT_NO_THROW(Helmet::createHelmet("Intelligence"));
    }