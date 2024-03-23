//
// Created by Sarah Amaniss on 2024-03-22.
//

#ifndef INC_345_ASG1_TANKBUILDER_H
#define INC_345_ASG1_TANKBUILDER_H

#include "fighter.h"

class TankBuilder {
private:
    fighter* fighter_;

public:
    TankBuilder();
    void setAbilities();
    void setLevel();
    void setHitPoints();
    void setArmorClass();
    void setAttackBonus();
    void setDamageBonus();
    void setItem();
    fighter* getFighter();
};


#endif //INC_345_ASG1_TANKBUILDER_H
