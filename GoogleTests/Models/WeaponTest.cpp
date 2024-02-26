//
// Created by jeanb on 25/02/2024.
//
#include <gtest/gtest.h>
#include "../../Models/Weapon.h"

TEST(WeaponCreation, GivenInvalidArgumentShouldThrowInvalidArgumentException) {
    EXPECT_THROW(Weapon::createWeapon("DamageBon"),std::invalid_argument);
    EXPECT_THROW(Weapon::createWeapon("AHHHHHHHH"),std::invalid_argument);
}
TEST(WeaponCreation, GivenValidArgumentShouldNotThrow) {
    EXPECT_NO_THROW(Weapon::createWeapon("DamageBonus"));
    EXPECT_NO_THROW(Weapon::createWeapon("AttackBonus"));
}