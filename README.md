# COMP 345 ASSIGNMENT 1 Pointer Masters 
**Team Members: **  
Jean-Baptiste Garibo 40223491  
Sarah Amaniss 40213883  
Steven Lam 40226649  
Marilyne Nguyen 40228396  

## project requirement
- IDE preferred: CLionNova or CLion  
- Compiler MinGW bundled from CLion  
- Cmake is needed to fetch the googletest library in order to run our unit tests, without it, you can't interpret the script from CMakeLists.txt

## project structure:
- driver.cpp (To run the future project)
  
- Models/ (Contains all the Models used in game, todo: clean the structure)
  * Items
  * ItemContainers
  * Characters
  * Map
  * Dice
- GoogleTest/
  * driverTest.cpp (Driver which runs all of our unit tests)
  * Models/ (Contains our classes to test and the writen test cases in each)
    * ItemsTests
    * CharactersTests
    * MapTest
    * DiceTest
## starting point
driver.cpp -> run some code, later the project
GoogleTests/driverTest.cpp -> run the unit tests
