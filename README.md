# COMP 345 Project: D&D Game  
## Team name: Pointer Masters 

  <img src="https://images.ctfassets.net/swt2dsco9mfe/G8hY5RaUUgMiwctolsI0K/1496009a9a957296d768d86e7503b5ca/157997_1920x1342.jpg?q=70" width="400" height="400">  



**Team Members:**  
Jean-Baptiste Garibo 40223491    
Sarah Amaniss 40213883    
Steven Lam 40226649    
Marilyne Nguyen 40228396    

## project requirement
- IDE preferred: CLion    
- Make sure to configure CMake before running the project, CMake will set the C++ version(17)    
- Cmake is also needed to fetch the googletest library in order to run our unit tests  

## project structure:
- driver.cpp (Run the project)
  
- Models/ (Contains all the Models used in game, todo: clean the structure, make itemsModels, characterModels mapModels folders)
  * Items
  * ItemContainers
  * Characters
  * Map
  * Dice
- Controllers/ (Contains the companent that interact/perform actions on the models)
  * CampaignEditorController
  * MapEditorController
  * CharacterEditorController
  * GameController
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
