#ifndef KNIGHT_H
#define KNIGHT_H

using namespace std;
#include <string>
#include "fighter.h"
#include "Observer.h"

class knight : public fighter, public Observer
{
protected:
    int chargingDamage;
    string companionAnimal;
    string knightWeapon;

public:
    /**
    Getter function to fetch the "chargingDamage" variable of the knight object
    @return int
    */
    int getChargingDamage();

    /**
    Getter function to fetch the "companionAnimal" variable of the knight object
    @return string
    */
    string getCompanionAnimal();

    /**
    Getter function to fetch the "knightWeapon" variable of the knight object
    @return string
    */
    string getKnightWeapon();

    /**
    Overriding the setHp method from the parent class, because a knight has a different range of values
    for hp variable. The value of "hp" variable depends on the level of the knight.
    @param param1 int level
    @return void
    */
    void setHp(int level) override;

    /**
    Method used to set a new value to the "chargingDamage" variable of the knight
    @param param1 int chargingDamage_
    @return void
    */
    void setChargingDamage(int chargingDamage_);

    /**
    Method used to attribute a value to "companionAnimal" of knight object, and its companion will depend
    on its level.
    @param param1 int level
    @return void
    */
    void setCompanionAnimal(int level);

    /**
    Method used to attribute a value to "knightWeapon" of knight object, and the weapon that the knight can
    access will depend on its level.
    @param param1 int level
    @return void
    */
    void setKnightWeapon(int level);

    /**
    Constructor for a knight object, which calls the parents constructor (fighter) to set its variable, and
    it then sets its own variable by calling setter functions.
    @param param1 int level
    @param param1 int chargingDamage_
    @return
    */
    knight(int level, int chargingDamage_);

    /**
    Overriding method from the parent class to display variables of the knight object
    @return
    */
    void displayCharacter() override;

    void update() override;
};

#endif