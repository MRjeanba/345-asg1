#ifndef WIZARD_H
#define WIZARD_H

using namespace std;
#include <string>
#include "fighter.h"

class wizard : public fighter, public Observer
{
  string wizardType;
  string spell;
  string wizardWeapon;

public:
  /**
  Getter function to fetch the "wizardType" variable of the wizard object.
  @return string
  */
  string getWizardType();

  /**
  Getter function to fetch the "spell" variable of the wizard object.
  @return string
  */
  string getSpell();

  /**
  Getter function to fetch the "wizardWeapon" variable of the wizard object.
  @return string
  */
  string getWizardWeapon();

  /**
  Overriding method from parent class, since a wizard character has a different range of values for it hp,
  which will depend on the level of the wizard object
  @param param1 int hp_
  @return void
  */
  void setHp(int hp_) override;

  /**
  This method is used to set a new value to variable "wizardType" of wizard object
  @return void
  */
  void setWizardType();

  /**
  This method is used to set a new value to variable "spell" of wizard object. There is 2 different spells
  available for each level, and the spell the wizard is going to acquire will be chosen randomly depending
  on its level
  @param param1 int level
  @return void
  */
  void setSpell(int level);

  /**
  This method is used to set a new value to variable "wizardWeapon" of wizard object. There is 2 different
  weapons available for each level, and the weapon the wizard is going to acquire will be chosen randomly
  depending on its level
  @param param1 int level
  @return void
  */
  void setWizardWeapon(int level);

  /**
  Constructor for a knight object, which calls the parents constructor (fighter) to set its variable, and
  it then sets its own variable by calling setter functions.
  @param param1 int level
  @return
  */
  wizard(int level);

  /**
  Overriding method from the parent class to display variables of the knight object
  @return
  */
  void displayCharacter() override;

  void update();//override;
  void update(const std::string &message) override;
};

#endif