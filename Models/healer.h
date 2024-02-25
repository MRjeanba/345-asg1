#ifndef HEALER_H
#define HEALER_H

using namespace std; 
#include <string>
#include <vector>
#include "fighter.h"


class healer : public fighter
{
    protected:
        vector<string> power;


    public:
        vector<string> getPower();

        void setPower(int level);
        void setHp(int level) override;

        healer(int level);
        void displayCharacter() override;


       
};

#endif
