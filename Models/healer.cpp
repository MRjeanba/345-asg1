#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "healer.h"
using namespace std;

healer::healer(int level) : fighter(level)
{
    setPower(level);
    setHp(level);
}

vector<string> healer::getPower()
{
    return power;
}

void healer::setPower(int level)
{
    string powers[5] = {"Healing Touch", "Protective Ward", "Revitalize", "Purification", "Empathic Connection"};
    for(int i = 0 ; i <= level ; i++)
    {
        power.push_back(powers[i]);
    }
}

void healer::setHp(int level)
{
    int hpLevel[5] = {400, 450, 500, 550, 600};
    hp = hpLevel[level];
}


void healer::displayCharacter()
{
    cout<< "Display of the healer: "<< endl; 
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
    cout<< "Powers : "<< endl;
    for (const auto& str : getPower()) {
        cout << str << " ";
    }
}
