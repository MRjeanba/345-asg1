#include <iostream>
#include <string>
#include "fighter.h"

using namespace std;

// Strategy Interface
class CharacterActionStrategy:public fighter {
public:
    virtual void move() = 0;
    virtual void attack() = 0;
    virtual void freeActions() = 0;
    virtual ~CharacterActionStrategy() {}
};

class HumanPlayerStrategy : public CharacterActionStrategy 
{
    public:
        void move() override 
        {
            cout << "Player can decide where to move." << std::endl;
            int x, y;
            cout << "Enter x coordinate: ";
            cin >> x;
            cout << "Enter y coordinate: ";
            cin >> y;

            fighter::setXPosition(x);
            fighter::setYPosition(y);
        }

        // must allow player to choose random player from npc list
        void attack() override 
        {
            fighter* npc = generateNpc(5);
            int index = 0;
            std::cout << "To choose a player to attack, enter a number from 1 to 5" << std::endl;
            cin >> index;
            fighter attackedPlayer = npc[index - 1];
            attackedPlayer.setHp(getHp() - 50);
        }

        void freeActions() override 
        {
            std::cout << "Choose what action action you would to perform : " << std::endl;
        }
};

class AggressorStrategy : public CharacterActionStrategy 
{
    public:
        // choose random player from npc list and change coordinates to npc's coordinates
        void move() override
        {
            std::cout << "Aggressor moves towards and attacks the player character." << std::endl;
            fighter* npc = generateNpc(5);
            int index = 0;
            std::cout << "To choose a player to attack, enter a number from 1 to 5" << std::endl;
            cin >> index;
            fighter attackedPlayer = npc[index - 1];
            this->setXPosition(attackedPlayer.getXPosition());
            this->setYPosition(attackedPlayer.getYPosition());
            attackedPlayer.setHp(getHp() - 50);
        }

        void attack() override
        {
            
        }

        void freeActions() override 
        {
            std::cout << "Choose what action action you would to perform : " << std::endl;
        }
};

class FriendlyStrategy : public CharacterActionStrategy 
{
    private:
        AggressorStrategy* currentStrategy;

    public:
        void move() override 
        {
            cout << "Player can decide where to move" << std::endl;
            int x, y;
            cout << "Enter x coordinate: ";
            cin >> x;
            cout << "Enter y coordinate: ";
            cin >> y;

            fighter::setXPosition(x);
            fighter::setYPosition(y);
        }

        void attack() override 
        {
            int intialHp = getHp();
            if(getHp() != intialHp)
            {
                currentStrategy->attack();
            }
        }

        void freeActions() override 
        {
            std::cout << "Choose what action action you would to perform : " << std::endl;
        }
};

// Context
// class Character 
// {
//     private:
//         CharacterActionStrategy* actionStrategy;
//     public:
//         Character(CharacterActionStrategy* strategy) : actionStrategy(strategy) {}

//         ~Character() 
//         {
//             delete actionStrategy;
//         }

//         void performTurn() 
//         {
//             actionStrategy->move();
//             actionStrategy->attack();
//             actionStrategy->freeActions();
//         }
// };

// Main function for testing
int main() 
{
   
}
