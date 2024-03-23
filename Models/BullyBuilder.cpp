//
// Created by Sarah Amaniss on 2024-03-21.
//

#include "fighter.h"
#include "BullyBuilder.h"

BullyBuilder::BullyBuilder() {
    fighter_ = new fighter(1);
}

void BullyBuilder::setAbilities() {
    fighter_->setStrength(1);
    fighter_->setConstitution(1);
    fighter_->setWisdom(1);
    fighter_->setIntelligence(1);
    fighter_->setCharisma(1);
}

void BullyBuilder::setLevel() {
    fighter_->setLevel(1);
}

void BullyBuilder::setHitPoints() {
    // Calculate and set hit points for a bully fighter
}

void BullyBuilder::setArmorClass() {
    // Calculate and set armor class for a bully fighter
}

void BullyBuilder::setAttackBonus() {
    // Calculate and set attack bonus for a bully fighter
}

void BullyBuilder::setDamageBonus() {
    // Calculate and set damage bonus for a bully fighter
}

void BullyBuilder::setItem() {
    // Set item for a bully fighter
    fighter_->setItem(/* Item value */);
}

fighter* BullyBuilder::getFighter() {
    return fighter_;
}






