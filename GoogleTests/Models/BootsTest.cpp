//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Boots.h"

/**
 * This test verify that the BootsCreation behaves correctly
 * In this case we expect that with a wrong enchantmentType the creation should throw an error
 */
TEST(BootsCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Boots::createBoots("DamageBonus"),std::invalid_argument);
    EXPECT_THROW(Boots::createBoots("AHHHHHHHH"),std::invalid_argument);
}

/**
 * This test verify that the BootsCreation behaves correctly
 * In this specific case, we verify that no errors are thrown during the Boots class creation
 */
TEST(BootsCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Boots::createBoots("ArmorClass"));
    EXPECT_NO_THROW(Boots::createBoots("Dexterity"));
}