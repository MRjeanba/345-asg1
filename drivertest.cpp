#include <iostream>
#include "Models/Map.cpp"
using namespace std;

int main()
{
    // testMap.displayMap();
    Map testMap(10, 10);
    testMap.displayMap();

    // Observer objects
    MapObserver *obs1;
    MapObserver *obs2;
    MapObserver *obs3;

    testMap.registerObserver(obs1);
    testMap.registerObserver(obs2);
    testMap.registerObserver(obs3);

    testMap.setCellType(3, 4, CellType::Wall);

    testMap.unregisterObserver(obs3);

    //Testing the Builder Pattern 

    return 0;
};