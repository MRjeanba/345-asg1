//
// Created by Sarah Amaniss on 2024-03-21.
//

#include "fighter.h"
#include "BullyBuilder.h"
#include "Dice.h"

BullyBuilder::BullyBuilder() {
    fighter_ = new fighter(1);
}

void BullyBuilder::setAbilities() {

    Dice rollDice;

    vector<int> diceResults;
    for (int i = 0; i < 5; ++i) {
        int result = rollDice.rollDice("1d6+0"); // Roll a d6
        diceResults.push_back(result);
    }

    sort(diceResults.begin(), diceResults.end());

    fighter_->setStrength(diceResults[0]);
    fighter_->setConstitution(diceResults[1]);
    fighter_->setDexterity(diceResults[2]);
    fighter_->setIntelligence(diceResults[3]);
    fighter_->setCharisma(diceResults[4]);
    fighter_->setWisdom(diceResults[5]);

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






