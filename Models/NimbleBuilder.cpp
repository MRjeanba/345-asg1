//
// Created by Sarah Amaniss on 2024-03-22.
//

#include "NimbleBuilder.h"
// NimbleBuilder.cpp
#include "NimbleBuilder.h"

NimbleBuilder::NimbleBuilder() {
    fighter_ = new fighter(1); // Assuming level 1 for simplicity
}

void NimbleBuilder::setAbilities() {
    fighter_->setDexterity(1);
    fighter_->setConstitution(1);
    fighter_->setWisdom(1);
    fighter_->setIntelligence(1);
    fighter_->setCharisma(1);
}

void NimbleBuilder::setLevel() {
    fighter_->setLevel(1);
}

void NimbleBuilder::setHitPoints() {
    // Calculate and set hit points for a nimble fighter
}

void NimbleBuilder::setArmorClass() {
    // Calculate and set armor class for a nimble fighter
}

void NimbleBuilder::setAttackBonus() {
    // Calculate and set attack bonus for a nimble fighter
}

void NimbleBuilder::setDamageBonus() {
    // Calculate and set damage bonus for a nimble fighter
}

void NimbleBuilder::setItem() {
    // Set item for a nimble fighter
    fighter_->setItem(/* Item value */);
}

fighter* NimbleBuilder::getFighter() {
    return fighter_;
}
