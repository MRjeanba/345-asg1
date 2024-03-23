//
// Created by Sarah Amaniss on 2024-03-22.
//

#include "TankBuilder.h"
#include "Dice.h"

TankBuilder::TankBuilder() {
    fighter_ = new fighter(1); // Assuming level 1 for simplicity
}

void TankBuilder::setAbilities() {
    Dice rollDice;

    vector<int> diceResults;
    for (int i = 0; i < 5; ++i) {
        int result = rollDice.rollDice("1d6+0"); // Roll a d6
        diceResults.push_back(result);
    }

    sort(diceResults.begin(), diceResults.end());

    fighter_->setConstitution(diceResults[1]);
    fighter_->setDexterity(diceResults[0]);
    fighter_->setStrength(diceResults[2]);
    fighter_->setIntelligence(diceResults[3]);
    fighter_->setCharisma(diceResults[4]);
    fighter_->setWisdom(diceResults[5]);

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
