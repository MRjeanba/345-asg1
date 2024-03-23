
#include "NimbleBuilder.h"
#include "Dice.h"

NimbleBuilder::NimbleBuilder() {
    fighter_ = new fighter(1); // Assuming level 1 for simplicity
}

void NimbleBuilder::setAbilities() {
    Dice rollDice;

    vector<int> diceResults;
    for (int i = 0; i < 5; ++i) {
        int result = rollDice.rollDice("1d6+0"); // Roll a d6
        diceResults.push_back(result);
    }

    sort(diceResults.begin(), diceResults.end());

    fighter_->setDexterity(diceResults[0]);
    fighter_->setConstitution(diceResults[1]);
    fighter_->setStrength(diceResults[2]);
    fighter_->setIntelligence(diceResults[3]);
    fighter_->setCharisma(diceResults[4]);
    fighter_->setWisdom(diceResults[5]);

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
