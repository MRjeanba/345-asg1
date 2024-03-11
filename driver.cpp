#include <iostream>
#include "Models/Dice.cpp"
#include "Models/Armor.h"
#include "Controllers/MapEditorController.h"


int main()
{
    // // TEST CASES
    // Dice d;
    // d.rollDice("5d6+30");
    // cout << endl;
    // d.rollDice("4d20+100");
    // cout << endl;
    // d.rollDice("2d12+4");
    // cout << endl;
    // d.rollDice("12d4+31");
    // cout << endl;
    // // TESTING when the expression is invalid -> should return an error message
    // d.rollDice("12dd4+31");
    // d.rollDice("1s1d4e+31");
    // d.rollDice("13d4-31");

    // the following create a map, change it, then store it to a file, and after load it from a file.
    //Map map(3, 3); // Example dimensions
    //map.getHeight();

    // thats an example
    //string filename = "MapsXML/lol.xml";

    //saveMap(map,filename);
    //Map m2;
    //loadMap(m2,filename);
    // should output the same as map object
    //m2.getHeight();

    MapEditorController mapController = MapEditorController();
    mapController.displayMenu();

    return 0;
}
