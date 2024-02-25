#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "fighter.h"
using namespace std;

int fighter::generateRandomNum()
{
    srand(static_cast<unsigned>(time(nullptr)));
    int num = rand() % 20 + 1;
    return num;
}

fighter::fighter(int level_) : level(level_)
{
    generateAbilities(); 
    calculateHitPoints(); 
    calculateArmorClass(); 
    calculateAttackBonus(); 
    calculateDamageBonus(); 
    setHp(level_);
    setItem();
}

int fighter::getLevel()
{
    return level;
}

void fighter::setLevel(int level_) 
{
    if(level_ < 0 || level_ <= 5)
    {
        level = level_ -1;
    }
    else
    {
        //set the default to 1
        level = 1; 
    }
    
}

int fighter::getStrength() 
{
    return strength;
}

void fighter::setStrength(int strength_)
{
    strength = strength_;
}

int fighter::getDexterity()
{
    return dexterity;
}

void fighter::setDexterity(int dexterity_)
{
    dexterity = dexterity_;
}

int fighter::getConstitution() 
{
    return constitution;
}

void fighter::setConstitution(int constitution_)
{
    constitution = constitution_;
}

int fighter::getHitPoints() const
{
    return hitpoints;
}

void fighter::setHitPoints(int hitpoints_)
{
    hitpoints = hitpoints_;
}

int fighter::getArmorClass() const
{
    return armorClass;
}

void fighter::setArmorClass(int armorClass_)
{
    armorClass = armorClass_;
}

int fighter::getAttackBonus() const
{
    return attackBonus;
}

void fighter::setAttackBonus(int attackBonus_)
{
    attackBonus = attackBonus_;
}

int fighter::getDamageBonus() const
{
    return damageBonus;
}

void fighter::setDamageBonus(int damageBonus_)
{
    damageBonus = damageBonus_;
}

int fighter::getHp()
{
    return hp;
}

void fighter::setHp(int level)
{
    int hpLevel[5] = {100, 150, 200, 250,300};
    hp = hpLevel[level]; 
}

string fighter::getItem()
{
    return item;
}

void fighter::setItem()
{
    string items[6] = {"armor", "shield", "weapon", "boots", "ring", "helmet"};
    srand(static_cast<unsigned>(time(nullptr)));
    int num = rand() % 6;
    item = items[num];
}

void fighter::generateAbilities()
{   
    setStrength(generateRandomNum());
    setDexterity(generateRandomNum()); 
    setConstitution(generateRandomNum()); 
}

int fighter::calculateModifier(int abilityScore) const
{
    return (abilityScore - 10) / 2;
}

void fighter::calculateHitPoints()
{
    int modifier = calculateModifier(getConstitution());
    setHitPoints(modifier * getLevel());
}

void fighter::calculateArmorClass()
{
    int modifier = calculateModifier(getDexterity());
    setArmorClass(modifier + 10);
}

void fighter::calculateAttackBonus()
{
    int modifier = calculateModifier(getStrength());
    setAttackBonus(modifier + getLevel());
}

void fighter::calculateDamageBonus()
{
    int modifier = calculateModifier(getStrength());
    setDamageBonus(modifier);
}

void fighter::displayCharacter()
{
    cout<< "Display of the fighter: "<< endl; 
    cout<< "Level: " << getLevel() << endl; 
    cout<< "Strenght: " << getStrength() << endl; 
    cout<< "Dexterity: " << getDexterity() << endl; 
    cout<< "Constitution: " << getConstitution() << endl; 
    cout<< "Hit Points: " << getHitPoints() << endl; 
    cout<< "Armor Class: " << getArmorClass() << endl; 
    cout<< "AttackBonus: " << getAttackBonus() << endl; 
    cout<< "DamageBonus: " << getDamageBonus() << endl; 
    cout<< "HP: " << getHp() << endl; 
    cout<< "Item: " << getItem() << endl; 
}


