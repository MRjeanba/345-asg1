#include <iostream>
#include "Models/Item.h"
#include "Models/Helmet.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Helmet test = Helmet::CreateHelmet("Intelligence");
    return 0;
}
