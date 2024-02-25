#ifndef FIGHTER_H
#define FIGHTER_H
using namespace std; 
#include <string>

class fighter
{
    protected:
        int level;
        int strength;
        int dexterity;
        int constitution;
        int hitpoints;
        int armorClass;
        int attackBonus;
        int damageBonus;
        int hp;
        string item;


    public:
        fighter(int level_);
        int getLevel();
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getHitPoints() const;
        int getArmorClass() const; 
        int getAttackBonus() const; 
        int getDamageBonus() const; 
        int getHp();
        string getItem();

        void setLevel(int level_);
        void setStrength(int strength_);
        void setDexterity(int dexterity_);
        void setConstitution(int constitution_);
        void setHitPoints(int hitpoints_);
        void setArmorClass(int armorClass_);
        void setAttackBonus(int attackBonus_); 
        void setDamageBonus(int damageBonus_);
        virtual void setHp(int level);
        void setItem();  

        int generateRandomNum();
        void generateAbilities(); 
        void calculateHitPoints(); 
        void calculateArmorClass(); 
        void calculateAttackBonus();
        void calculateDamageBonus(); 
        int calculateModifier(int abilityScore) const; 
        virtual void displayCharacter(); 
};

#endif
