//
// Created by Sarah Amaniss on 2024-03-22.
//

#include "TankBuilder.h"
// TankBuilder.cpp
#include "TankBuilder.h"

TankBuilder::TankBuilder() {
    fighter_ = new fighter(1); // Assuming level 1 for simplicity
}

void TankBuilder::setAbilities() {
    fighter_->setConstitution(1);
    fighter_->setStrength(1);
    fighter_->setWisdom(1);
    fighter_->setIntelligence(1);
    fighter_->setCharisma(1);
}

void TankBuilder::setLevel() {
    fighter_->setLevel(1);
}

void TankBuilder::setHitPoints() {
    // Calculate and set hit points for a tank fighter
}

void TankBuilder::setArmorClass() {
    // Calculate and set armor class for a tank fighter
}

void TankBuilder::setAttackBonus() {
    // Calculate and set attack bonus for a tank fighter
}

void TankBuilder::setDamageBonus() {
    // Calculate and set damage bonus for a tank fighter
}

void TankBuilder::setItem() {
    // Set item for a tank fighter
    fighter_->setItem(/* Item value */);
}

fighter* TankBuilder::getFighter() {
    return fighter_;
}
