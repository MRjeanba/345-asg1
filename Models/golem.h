#ifndef GOLEM_H
#define GOLEM_H

using namespace std; 
#include <string>
#include <vector>
#include "fighter.h"


class golem : public fighter
{
    protected:
        string golemType;
        vector<string> attacks;

    public:
        string getGolemType();
        vector<string> getAttacks();

        void setHp(int level) override;
        void setGolemType();
        void setAttacks(int level);

        golem(int level);
        void displayCharacter() override;
};

#endif
