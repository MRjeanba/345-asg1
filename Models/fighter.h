#ifndef FIGHTER_H
#define FIGHTER_H

#include "EnchantmentInfo.h"
#include "Observable.h"
#include <string>
#include <map>
using namespace std;

class fighter : public Observable {
protected:
    int level;
    int strength;
    int dexterity;
    int constitution;
    int wisdom;
    int charisma;
    int intelligence;
    int hitpoints;
    int armorClass;
    int attackBonus;
    int damageBonus;
    int hp;
    string item;
    EnchantmentInfo enchantmentsDetails;

public:
    /**
    This is the constructor method for a fighter object, which sets all the variables for a fighter object
    by using methods defined. Certain variables will depend on the level of the fighter, which means that
    methods are called with "level_" as a parameter.
    @param level_ int level in range 1 to 5
    @return
    */
    fighter(int level_);

    fighter();

    /**
    Getter function to fetch the "level" variable of the fighter object
    @return int
    */
    int getLevel();

    /**
    Getter function to fetch the "strength" of the fighter object
    @return int
    */
    int getStrength();

    /**
    Getter function to fetch the "wisdom" of the fighter object
    @return int
    */
    int getWisdom();

    /**
    Getter function to fetch the "intelligence" of the fighter object
    @return int
    */
    int getIntelligence();

    /**
    Getter function to fetch the "charisma" of the fighter object
    @return int
    */
    int getCharisma();

    /**
    Getter function to fetch the "dexterity" variable of the fighter object
    @return int
    */
    int getDexterity();

    /**
    Getter function to fetch the "constitution" variable of the fighter object
    @return int
    */
    int getConstitution();

    /**
    Getter function to fetch the "hitpoints" variable of the fighter object, "const" keyword is used
    to indicate that this method should not change the value of the variable.
    @return int
    */
    int getHitPoints() const;

    /**
    Getter function to fetch the "armorClass" variable of the fighter object, "const" keyword is used
    to indicate that this method should not change the value of the variable.
    @return int
    */
    int getArmorClass() const;

    /**
    Getter function to fetch the "attackBonus" variable of the fighter object, "const" keyword is used
    to indicate that this method should not change the value of the variable.
    @return int
    */
    int getAttackBonus() const;

    /**
    Getter function to fetch the "damageBonus" variable of the fighter object, "const" keyword is used
    to indicate that this method should not change the value of the variable.
    @return int
    */
    int getDamageBonus() const;

    /**
    Getter function to fetch the "hp" variable of the fighter object
    @return int
    */
    int getHp();

    /**
    Getter function to fetch the "item" variable of the fighter object
    @return string
    */
    string getItem();

    /**
    This method is used to set a new value to variable "level" of fighter object
    @param param1 int level_
    @return void
    */
    void setLevel(int level_);

    /**
    This method is used to set a new value to variable "strength" of fighter object
    @param param1 int strength
    @return void
    */
    void setStrength(int strength_);

    /**
    This method is used to set a new value to variable "wisdom" of fighter object
    @param param1 int wisdom
    @return void
    */
    void setWisdom(int wisdom_);

    /**
    This method is used to set a new value to variable "intelligence" of fighter object
    @param param1 int intelligence
    @return void
    */
    void setIntelligence(int intelligence_);

    /**
    This method is used to set a new value to variable "charisma" of fighter object
    @param param1 int charisma
    @return void
    */
    void setCharisma(int charisma_);

    /**
    This method is used to set a new value to variable "dexterity" of fighter object
    @param param1 int dexterity
    @return void
    */
    void setDexterity(int dexterity_);

    /**
    This method is used to set a new value to variable "constitution" of fighter object
    @param param1 int constitution
    @return void
    */
    void setConstitution(int constitution_);

    /**
    This method is used to set a new value to variable "hitpoints" of fighter object
    @param param1 int hitpoints
    @return void
    */
    void setHitPoints(int hitpoints_);

    /**
    This method is used to set a new value to variable "armorClass" of fighter object
    @param param1 int armorClass
    @return void
    */
    void setArmorClass(int armorClass_);

    /**
    This method is used to set a new value to variable "attackBonus" of fighter object
    @param param1 int attackBonus
    @return void
    */
    void setAttackBonus(int attackBonus_);

    /**
    This method is used to set a new value to variable "DamageBonus" of fighter object
    @param param1 int damageBonus
    @return void
    */
    void setDamageBonus(int damageBonus_);

    /**
    This method is used to set a new value to variable "hp" of fighter object. This method is also made
    virtual, since it is going to be overridden in child class.
    @param param1 int hep
    @return void
    */
    virtual void setHp(int level);

    /**
    This method is used to set a new value to variable "item" of fighter object
    @param param1 int item
    @return void
    */
    void setItem();

    /**
    This method is used to generate a random value from 1 to 20 and it is going to be used by setter functions
    of other variables to set their values randomly.
    @return int
    */
    int generateRandomNumFromTheDice();

    /**
    This method set the values for 3 variables (strength, dexterity, constitution) of fighter class. It does
    this, by using the setter functions of these 3 variables, which in turn invoke generateRandomNumber() method
    to randomly set the values of these abilities.
    @return void
    */
    void generateAbilities();

    /**
    This method calculate the "hitpoint" variable of the fighter class, and this value depends on the value of
    the constitution and level variables of the fighter object
    @return int
    */
    void calculateHitPoints();

    /**
    This method calculate the "hitpoint" variable of the fighter class, and this value depends on the value of
    the dexterity variable of the fighter object
    @return void
    */
    void calculateArmorClass();

/**
This method calculate the "hitpoint" variable of the fighter class, and this value depends on the value of
    the strength and level variables of the fighter object
    @return void
    */
    void calculateAttackBonus();

    /**
    This method calculate the "hitpoint" variable of the fighter class, and this value depends on the value of
    the strength variable of the fighter object
    @return void
    */
    void calculateDamageBonus();

    /**
    This method calculate a value depending on the parameter passed to the function. It is a helper method
    to the setter function
    @return int
    */
    int calculateModifier(int abilityScore) const;

    /**
    This method is used to display all the values of the variables of the fighter object on the terminal and
    it is meant to be overridden in child classes.
    @return void
    */
    virtual void displayCharacter();


    /**
     * Get the enchantment characteristics of the user, if the instance is decorated by items, these will add their
     * enchantment bonus to the corresponding enchantmentType of the character
     * @return a map<string,int> from enchantmentType to Bonus
     */
    virtual map<string,int> getEnchantmentsCharacteristics();

    /**
     * Get the type of the current fighter instance
     * @return a string indicating the type
     */
    virtual string getType();

    /**
     * Get the type of the current fighter instance but also the type of all the decorators wrapping the fighter
     * @return a string aggregating the types
     */
    virtual string getTypes();

    /**
    This method is used to update fighter and notify observers
    @return void
    */
    virtual void updateFighter();

    void attachObserver(Observer* observer) {
        registerObserver(observer);
    }

    void attack(const std::string& result);

};

#endif