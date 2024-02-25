#ifndef KNIGHT_H
#define KNIGHT_H

using namespace std; 
#include <string>
#include "fighter.h"


class knight : public fighter
{
    protected:
        int chargingDamage;
        string companionAnimal;
        string knightWeapon;

    public:
        int getChargingDamage();
        string getCompanionAnimal();
        string getKnightWeapon();

        void setHp(int level) override;
        void setChargingDamage(int chargingDamage_);
        void setCompanionAnimal(int level);
        void setKnightWeapon(int level);

        knight(int level, int chargingDamage_);
        void displayCharacter() override;

};

#endif
