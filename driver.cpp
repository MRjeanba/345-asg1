#include <iostream>

#include "Models/Armor.h"
#include "Models/Item.h"
#include "Models/Helmet.h"
#include "Models/Shield.h"

int main() {
    Shield test = Shield::createShield("ArmorClass");
    return 0;
}