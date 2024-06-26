#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "fighter.h"
#include "Observable.h"
#include "Dice.h"
#include <fstream> // Include the file stream library

using namespace std;

/**
 * Generate a random number between 1 and 20
 * @return int
 */
int fighter::generateRandomNumFromTheDice()
{
//    srand(static_cast<unsigned>(time(nullptr)));
//    int num = rand() % 20 + 1;
    Dice d;
    int level = this->getLevel();
    int num = 0;

    switch(level)
    {
        case 1:
            num =  d.rollDice("4d6+1");
            break;
        case 2:
             num =  d.rollDice("4d6+2");
             break;
        case 3:
             num =  d.rollDice("4d6+3");
             break;
        case 4:
             num =  d.rollDice("4d6+4");
             break;
        case 5:
            num =  d.rollDice("4d6+4");
            break;
        default:
            num = 15;
    };
    return num;
}

/**
 * Constructor for fighter class
 * @param level_ int Level of the fighter
 */
fighter::fighter(int level_)
{
    setLevel(level_);
    generateAbilities();
    calculateHitPoints();
    calculateArmorClass();
    calculateAttackBonus();
    calculateDamageBonus();
    setHp(level_);
    setItem();
}

/**
 * Default constructor for fighter class
 */
fighter::fighter(): level(0), strength(0), intelligence(0), wisdom(0), charisma(0), dexterity(0), constitution(0), hitpoints(0), armorClass(0), attackBonus(0),
                    damageBonus(0), hp(0) {}

/**
 * Getter function for the level of the fighter
 * @return int
 */
int fighter::getLevel()
{
    return level;
}

/**
 * Setter function for the level of the fighter
 * @param level_ int Level to set
 */
void fighter::setLevel(int level_)
{
    level = std::max(1, std::min(level_, 5));
}


/**
 * Getter function for the strength of the fighter
 * @return int
 */
int fighter::getStrength()
{
    return strength;
}

/**
 * Getter function for the charisma of the fighter
 * @return int
 */
int fighter::getCharisma()
{
    return charisma;
}

/**
 * Getter function for the wisdom of the fighter
 * @return int
 */
int fighter::getWisdom()
{
    return wisdom;
}

/**
 * Getter function for the intelligence of the fighter
 * @return int
 */
int fighter::getIntelligence() {
    return intelligence;
}

/**
 * Setter function for the strength of the fighter
 * @param strength_ int Strength to set
 */
void fighter::setStrength(int strength_)
{
    strength = strength_;
}

/**
 * Setter function for the wisdom of the fighter
 * @param wisdom_ int Wisdom to set
 */
void fighter::setWisdom(int wisdom_)
{
    wisdom = wisdom_;
}

/**
 * Setter function for the intelligence of the fighter
 * @param intelligence_ int Intelligence to set
 */
void fighter::setIntelligence(int intelligence_)
{
    intelligence = intelligence_;
}

/**
 * Setter function for the charisma of the fighter
 * @param charisma_ int Charisma to set
 */
void fighter::setCharisma(int charisma_) {
    charisma = charisma_;
}

/**
 * Getter function for the dexterity of the fighter
 * @return int
 */
int fighter::getDexterity()
{
    return dexterity;
}

/**
 * Setter function for the dexterity of the fighter
 * @param dexterity_ int Dexterity to set
 */
void fighter::setDexterity(int dexterity_)
{
    dexterity = dexterity_;
}

/**
 * Getter function for the constitution of the fighter
 * @return int
 */
int fighter::getConstitution()
{
    return constitution;
}

/**
 * Setter function for the constitution of the fighter
 * @param constitution_ int Constitution to set
 */
void fighter::setConstitution(int constitution_)
{
    constitution = constitution_;
}

/**
 * Getter function for the hit points of the fighter
 * @return int
 */
int fighter::getHitPoints() const
{
    return hitpoints;
}

/**
 * Setter function for the hit points of the fighter
 * @param hitpoints_ int Hit points to set
 */
void fighter::setHitPoints(int hitpoints_)
{
    hitpoints = hitpoints_;
}

/**
 * Getter function for the armor class of the fighter
 * @return int
 */
int fighter::getArmorClass() const
{
    return armorClass;
}

/**
 * Setter function for the armor class of the fighter
 * @param armorClass_ int Armor class to set
 */
void fighter::setArmorClass(int armorClass_)
{
    armorClass = armorClass_;
}

/**
 * Getter function for the attack bonus of the fighter
 * @return int
 */
int fighter::getAttackBonus() const
{
    return attackBonus;
}

/**
 * Setter function for the attack bonus of the fighter
 * @param attackBonus_ int Attack bonus to set
 */
void fighter::setAttackBonus(int attackBonus_)
{
    attackBonus = attackBonus_;
}

/**
 * Getter function for the damage bonus of the fighter
 * @return int
 */
int fighter::getDamageBonus() const
{
    return damageBonus;
}

/**
 * Setter function for the damage bonus of the fighter
 * @param damageBonus_ int Damage bonus to set
 */
void fighter::setDamageBonus(int damageBonus_)
{
    damageBonus = damageBonus_;
}

/**
 * Getter function for the hit points of the fighter
 * @return int
 */
int fighter::getHp()
{
    return hp;
}

/**
 * Setter function for the hit points of the fighter
 * @param level int Level of the fighter
 */
void fighter::setHp(int level)
{
    int hpLevel[5] = {100, 150, 200, 250,300};
    hp = hpLevel[level];
}

/**
 * Getter function for the item of the fighter
 * @return string
 */
string fighter::getItem()
{
    return item;
}

/**
 * Setter function for the item of the fighter
 */
void fighter::setItem()
{
    string items[6] = {"armor", "shield", "weapon", "boots", "ring", "helmet"};
    srand(static_cast<unsigned>(time(nullptr)));
    int num = rand() % 6;
    item = items[num];
    inventory.push_back(item);
}

vector<string> fighter::getInventory()
{
    return inventory;
}

/**
 * Generate abilities (strength, dexterity, constitution, wisdom, intelligence, charisma) for the fighter
 */
void fighter::generateAbilities()
{
    cout << "Setting Wisdom Ability with d6 dice..." << endl;
    setWisdom(generateRandomNumFromTheDice());
    cout << "Setting Intelligence Ability with d6 dice..." << endl;
    setIntelligence(generateRandomNumFromTheDice());
    cout << "Setting Charisma Ability with d6 dice..." << endl;
    setCharisma(generateRandomNumFromTheDice());
    cout << "Setting Strength Ability with d6 dice..." << endl;
    setStrength(generateRandomNumFromTheDice());
    cout << "Setting Dexterity Ability with d6 dice..." << endl;
    setDexterity(generateRandomNumFromTheDice());
    cout << "Setting Constitution Ability with d6 dice..." << endl;
    setConstitution(generateRandomNumFromTheDice());
}

/**
 * Calculate the ability modifier based on the ability score
 * @param abilityScore int Ability score
 * @return int
 */
int fighter::calculateModifier(int abilityScore) const
{
    return (abilityScore - 10) / 2;
}

/**
 * Calculate the hit points of the fighter based on the constitution and level
 */
void fighter::calculateHitPoints()
{
    int modifier = calculateModifier(getConstitution());
//    setHitPoints(modifier * getLevel());
    Dice d;
    cout << endl << "Rolling a d20 dice... setting the HitPoints... " << endl;
    int resultDice = generateRandomNumFromTheDice();
    setHitPoints(modifier * resultDice);
}

/**
 * Calculate the armor class of the fighter based on the dexterity
 */
void fighter::calculateArmorClass()
{
    int modifier = calculateModifier(getDexterity());
    setArmorClass(modifier + 10);
}

/**
 * Calculate the attack bonus of the fighter based on the strength and level
 */
void fighter::calculateAttackBonus()
{
    cout << endl << "Rolling a d20 dice... setting the AttackBonus... " << endl;
    int modifier = calculateModifier(getStrength());
    setAttackBonus(modifier + generateRandomNumFromTheDice());
}

/**
 * Calculate the damage bonus of the fighter based on the strength
 */
void fighter::calculateDamageBonus()
{
    int modifier = calculateModifier(getStrength());
    setDamageBonus(modifier);
}

/**
 * Update the fighter's attributes when leveling up
 */
void fighter::updateFighter() {
    level++;
    calculateHitPoints();
    calculateArmorClass();
    calculateAttackBonus();
    calculateDamageBonus();
    setHp(level);
    setItem();
    notifyObservers("The fighter is updated");
}

/**
 * Display the details of the fighter
 */
void fighter::displayCharacter()
{
    cout<< endl;
    cout<< endl << "Display of the fighter:\n "<< endl;
    cout<< "Level: " << getLevel() << endl;
    cout<< "Strength: " << getStrength() << endl;
    cout<< "Wisdom: " << getWisdom() << endl;
    cout<< "Intelligence: " << getIntelligence() << endl;
    cout<< "Charisma: " << getCharisma() << endl;
    cout<< "Dexterity: " << getDexterity() << endl;
    cout<< "Constitution: " << getConstitution() << endl;
    cout<< "Hit Points: " << getHitPoints() << endl;
    cout<< "Armor Class: " << getArmorClass() << endl;
    cout<< "Attack Bonus: " << getAttackBonus() << endl;
    cout<< "Damage Bonus: " << getDamageBonus() << endl;
    cout<< "HP: " << getHp() << endl;
    cout<< "Item: " << getItem() << endl;
    cout<< "Inventory: ";
    for (const auto &str : getInventory())
    {
        cout << str << " ";
    }
    //where does this come from ...
    cout << "\nWe rolled the dice! You're a BULLY fighter! " << endl;
    cout << endl;

}

/**
 * Perform an attack action by the fighter
 * @param result string Result of the attack
 */
void fighter::attack(const std::string& result)
{
    notifyObservers("Attack attempted and its result: " + result);
}


/**
 * Get the type of the fighter
 * @return string
 */
string fighter::getType() {
    return "character";
}

/**
 * Function used for the decorator pattern, used from Worn items and recurse up to the character
 * Since the character is not an item we don't want to output it so we return an empty string
 * @return string an empty string serving as a base case to stop the recursion
 */
string fighter::getTypes() {
    return "";
}

void fighter::setWornItemsPtr(CharacterWornItems *wornItemsContainer) {
    this->wornItemsPtr = wornItemsContainer;
}

CharacterWornItems * fighter::getWornItemsPtr() { return wornItemsPtr; }

void fighter::removeItem() {
    wornItemsPtr->removeFromWornItems();
}

void fighter::wearItem(WornItemsDecorator * itemToWear) {
    wornItemsPtr->wearItem(itemToWear);
}

void fighter::getWornItems() {
    wornItemsPtr->getWornItems();
}

/* Depending on the usage of the roll we choose a different type of dice
 * xdy[+z] -> x will always be 1 for one dice (maybe depending on the level we can change the number of dices available)
 * 1 - Dice could be used for the modifiers of fighter characteristics
 * (instead of random numbers)
 * 2 - Dice could be rolled when the user wants to attack to see how much damage it
 * could make
 * 3 - Dice could be used when the character wants to destroy a wall
 *  -> must have a number greater than a certain value to be able to destroy it
 * 4 - Dice display to make sure the user is respecting the game's rules
 *
 */

/*
 * Mandatory class is Fighter, which can attack using either a bow (or other ranged weapon)
 * or sword (or other melee weapon), and wear light, medium or heavy armor and a shield.
 *
 * Armor class (light, medium, heavy)
 * Shield class
 * create an object from armor and shield classes for the fighter
 * Armor object (light, medium, heavy)
 * light -> less "protection points" -> can be damaged easily
 * medium -> moderate "protection points" -> can be damaged moderately
 * heavy -> high "protection points" -> can be damaged but will take a lot of hit points
 * Shield object -> its value could be the same for every character
 */