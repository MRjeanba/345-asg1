//
// Created by Sarah Amaniss on 2024-03-21.
//

#ifndef INC_345_ASG1_BULLYBUILDER_H
#define INC_345_ASG1_BULLYBUILDER_H

#include "fighter.h"

class BullyBuilder {

private:
    fighter* fighter_;

public:
    BullyBuilder();
    void setAbilities();
    void setLevel();
    void setHitPoints();
    void setArmorClass();
    void setAttackBonus();
    void setDamageBonus();
    void setItem();
    fighter* getFighter();
};


#endif //INC_345_ASG1_BULLYBUILDER_H
