//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Armor.h"

    /**
     * This test verify that the ArmorCreation behaves correctly
     * In this case we expect that with a wrong enchantmentType the creation should throw an error
     */
    TEST(ArmorCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
        EXPECT_THROW(Armor::createArmor("DamageBonus"),std::invalid_argument);
        EXPECT_THROW(Armor::createArmor("AHHHHHHHH"),std::invalid_argument);
    }

    /**
     * This test verify that the ArmorCreation behaves correctly
     * In this specific case, we verify that no errors are thrown during the Armor class creation
     */
    TEST(ArmorCreation, GivenValidArgumentShouldNotThrow) {
            EXPECT_NO_THROW(Armor::createArmor("ArmorClass"));
    }