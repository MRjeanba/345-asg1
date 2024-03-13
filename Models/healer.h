#ifndef HEALER_H
#define HEALER_H

using namespace std;
#include <string>
#include <vector>
#include "fighter.h"
#include "Observer.h"
#include "Observable.h" // Include the Observable class

/**
 * Healer class, child of fighter
 * included vector libraries, because for its attacks adjustable array are needed
 */
class healer : public fighter, public Observer {
protected:
    vector<string> power;

public:
    /**
      * Getter for powers that the healer can do
      @return vector <string> of the powers
      */
    vector<string> getPower();

    /**
      * Setter for the powers that the healer can do
      * The more the healer is advanced, the more powers are accessible to him
      @param int level (between 1 to 5)
      @return void
      */
    void setPower(int level);

    /**
    *Setter for the HP of the Healer depending on its level
    Override the base's class method
    @param int level(between 1 to 5)
    @return void
    */
    void setHp(int level) override;

    /**
     * Healer's constructor
     * Child of Fighter class
     * inheriting the base's class properties
     * setting the healer's power and the hp
    @param param1 int level (between 1 to 5)
    */
    healer(int level);

    void update() override;

    /**
     * displayCharacter() displays the characteristics of the healer such as powers, etc.
     * Overriding the base's class displayCharacter
    @return void
    */
    void displayCharacter() override;
};

#endif
