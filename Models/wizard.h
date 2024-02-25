#ifndef WIZARD_H
#define WIZARD_H

using namespace std; 
#include <string>
#include "fighter.h"


class wizard : public fighter
{
      string wizardType;
      string spell;
      string wizardWeapon;

    public:
      string getWizardType();
      string getSpell();
      string getWizardWeapon();

      void setHp(int hp_) override;
      void setWizardType();
      void setSpell(int level);
      void setWizardWeapon(int level);

      wizard(int level); 
      void displayCharacter() override;


       
};

#endif
