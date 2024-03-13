#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "knight.h"
using namespace std;

knight::knight(int level, int chargingDamage_) : fighter(level), chargingDamage(chargingDamage_)
{
    setCompanionAnimal(level);
    setHp(level);
    setKnightWeapon(level);
}

void knight::setHp(int level)
{
    int hpLevel[5] = {300, 350, 400, 450,500};
    hp = hpLevel[level];
}

int knight::getChargingDamage()
{
    return chargingDamage;
}

void knight::setChargingDamage(int chargingDamage_)
{
    chargingDamage = chargingDamage_;
}

string knight::getCompanionAnimal()
{
    return companionAnimal;
}

void knight::setCompanionAnimal(int level)
{
    string companions[5] = {"dog", "horse", "falcon", "lion", "dragon"};
    companionAnimal =  companions[level - 1];
}

string knight::getKnightWeapon()
{
    return knightWeapon;
}

void knight::setKnightWeapon(int level)
{
    string weapons[5][2] = {
        {"Longsword", "Broadsword"},
        {"Battleaxe", "Morningstar"},
        {"Warhammer", "Lance"},
        {"Halberd", "Mace"},
        {"Rapier", "Crossbow"}
    };

    srand(static_cast<unsigned>(time(nullptr)));
    int param2 = rand() % 2;

    knightWeapon = weapons[level][param2];
}


void knight::displayCharacter()
{
    cout<< "Display of the knight: "<< endl; 
    cout<< "Level: " << getLevel() << endl; 
    cout<< "Strenght: " << getStrength() << endl; 
    cout<< "Dexterity: " << getDexterity() << endl; 
    cout<< "Constitution: " << getConstitution() << endl; 
    cout<< "Hit Points: " << getHitPoints() << endl; 
    cout<< "Armor Class: " << getArmorClass() << endl; 
    cout<< "AttackBonus: " << getAttackBonus() << endl; 
    cout<< "DamageBonus: " << getDamageBonus() << endl; 
    cout<< "Companion Animal: " << getCompanionAnimal() << endl;
    cout<< "hp: " << getHp() << endl;
    cout<< "Charging Damage: " << getChargingDamage() << endl;
    cout<< "Knight Weapon: " << getKnightWeapon() << endl;
    
}



