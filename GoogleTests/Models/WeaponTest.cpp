//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Weapon.h"

/**
 * This test verify that the WeaponCreation behaves correctly
 * In this case we expect that with a wrong enchantmentType the creation should throw an error
 */
TEST(WeaponCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Weapon::createWeapon("DamageBon"),std::invalid_argument);
    EXPECT_THROW(Weapon::createWeapon("AHHHHHHHH"),std::invalid_argument);
}

/**
 * This test verify that the WeaponCreation behaves correctly
 * In this specific case, we verify that no errors are thrown during the Weapon class creation
 */
TEST(WeaponCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Weapon::createWeapon("DamageBonus"));
    EXPECT_NO_THROW(Weapon::createWeapon("AttackBonus"));
}