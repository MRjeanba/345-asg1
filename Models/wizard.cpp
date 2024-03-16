#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "wizard.h"
using namespace std;

void wizard::setHp(int level)
{
    int hpLevel[5] = {200, 250, 300, 350, 400};
    hp = hpLevel[level];
}

string wizard::getWizardType()
{
    return wizardType;
}

void wizard::setWizardType()
{
    string types[3] = {"fire", "ice", "wind"};
    srand(static_cast<unsigned>(time(nullptr)));
    int typeIndex = rand() % 3;
    wizardType = types[typeIndex];
}

string wizard::getSpell()
{
    return spell;
}

void wizard::setSpell(int level)
{
    string spells[5][2] = {
        {"teleportation", "shield"},
        {"Summon Familiar", "Polymorph"},
        {"Illusion", "Telekinesis"},
        {"Enhancement", "Scrying"},
        {"Dispel Magic", "Elemental Fusion"}};
    srand(static_cast<unsigned>(time(nullptr)));
    int param2 = rand() % 2;
    cout << "param2 = " << param2;
    spell = spells[level][param2];
}

string wizard::getWizardWeapon()
{
    return wizardWeapon;
}

void wizard::setWizardWeapon(int level)
{
    string weapons[5][2] = {
        {"Spellbook", "Wand"},
        {"Robes of the Archmage", "Crystal Ball"},
        {"Potion Belt", "Familiar"},
        {"Arcane Focus", "Amulet of Spell Mastery"},
        {"Bag of Holding", "Ring of Protection"}};
    srand(static_cast<unsigned>(time(nullptr)));
    int param2 = rand() % 2;
    cout << "param2 = " << param2;

    wizardWeapon = weapons[level][param2];
}

wizard::wizard(int level) : fighter(level)
{
    setHp(level);
    setWizardType();
    setSpell(level);
    setWizardWeapon(level);
}

void wizard::displayCharacter()
{
    cout << "Display of the wizard: " << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Strenght: " << getStrength() << endl;
    cout << "Dexterity: " << getDexterity() << endl;
    cout << "Constitution: " << getConstitution() << endl;
    cout << "Hit Points: " << getHitPoints() << endl;
    cout << "Armor Class: " << getArmorClass() << endl;
    cout << "AttackBonus: " << getAttackBonus() << endl;
    cout << "DamageBonus: " << getDamageBonus() << endl;
    cout << "HP: " << getHp() << endl;
    cout << "Wizard Type: " << getWizardType() << endl;
    cout << "Spell: " << getSpell() << endl;
    cout << "Wizard Weapon: " << getWizardWeapon() << endl;
}

void wizard::update()
{
    std::cout << "Wizard received an update from Observable!" << std::endl;
}