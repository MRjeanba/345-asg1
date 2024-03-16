#ifndef GOLEM_H
#define GOLEM_H

using namespace std;
#include <string>
#include <vector>
#include "fighter.h"
#include "Observable.h"

/**
 * Golem class, child of fighter
 * Very strong character
 * included vector librairies, because for its attacks ajustable array are needed
 */

class golem : public fighter, public Observer
{
protected:
    string golemType;
    vector<string> attacks;

public:
    /**
     * Getter for the type of the Golem (earth,ice, wind)
     @return string golemType
     */
    string getGolemType();

    /**
     * Getter for the attacks that the golem can do
     @return vector <string> of the attacks
     */
    vector<string> getAttacks();

    /**
    *Setter for the HP of the Golem depending on its level
    Override the base's class method
    @param int level(between 1 to 5)
    @return void
    */
    void setHp(int level) override;
    /**
    *Getter for the Golem's type
    @return void
    */
    void setGolemType();
    /**
     * Setter for the golem's attacks
     * Depending on the golem's type and level
     * The attacks are different
     * The more advanced the golem is, the more attacks he is allowed to make
     * (Compound attacks)

    @param param1 int level (between 1 to 5)
    @return void
    */
    void setAttacks(int level);

    /**
     * Golem's constructor
     * Child of Fighter class
     * inheriting the base's class properties
     * setting the golem's type, the hp and its attacks
    @param param1 int level (between 1 to 5)
    */
    golem(int level);

    /**
     * displayCharacter() displays the characteristics of the golem such as its attacks, its type, etc.
     * Overriding the base's class displayCharacter
   @return void
   */
    void displayCharacter() override;

    /**
     * This method will update the golem
  @return void
*/
    void update() override;
};

#endif
