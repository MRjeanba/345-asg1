cmake_minimum_required(VERSION 3.27)
project(345_asg1)

set(CMAKE_CXX_STANDARD 17)

add_executable(345_asg1 driver.cpp
        Models/Item.cpp
        Models/Item.h
        Models/EnchantmentInfo.h
        Models/Helmet.cpp
        Models/Helmet.h
        Models/Armor.cpp
        Models/Armor.h
        Models/Shield.cpp
        Models/Shield.h
        Models/Ring.cpp
        Models/Ring.h
        Models/Belt.cpp
        Models/Belt.h
        Models/Boots.cpp
        Models/Boots.h
        Models/Weapon.cpp
        Models/Weapon.h
        Models/Map.h
        Models/Map.cpp
        Models/ItemContainer.cpp
        Models/ItemContainer.h
        Models/CharacterBackpack.cpp
        Models/CharacterBackpack.h
        Models/TreasureChest.cpp
        Models/TreasureChest.h
        Models/CharacterWornItems.cpp
        Models/CharacterWornItems.h
        Models/Campaign.cpp
        Models/Campaign.h

        Controllers/MapEditorController.cpp
        Controllers/MapEditorController.h
        Controllers/CampaignEditorController.cpp
        Controllers/CampaignEditorController.h
        Controllers/CharacterEditorController.cpp
        Controllers/CharacterEditorController.h
        Utilities.h
        driver.h

        Models/Observer.h
        Models/Observable.h
        Models/CharacterObserver.h
        Models/CharacterObserver.cpp
        Models/fighter.cpp
        Models/golem.cpp
        Models/golem.h
        Models/healer.h
        Models/healer.cpp
        Models/wizard.cpp
        Models/wizard.h
        Models/fighter.h
        Models/knight.cpp
        Models/knight.h
        Controllers/gameController.cpp
        Controllers/gameController.h
        Models/WornItemsDecorator.cpp
        Models/WornItemsDecorator.h
        Models/MapBuilder.h
        Controllers/ItemEditorController.cpp
        Controllers/ItemEditorController.h
        #        Models/GameLog.cpp
#        Models/GameLog.h
#        Models/GameController.cpp
#        Models/GameController.h
)


include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/9d43b27.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
set(unitTestFiles
        Models/Helmet.h
        GoogleTests/driverTest.cpp
        Models/Helmet.cpp
        Models/Item.h
        Models/Item.cpp
        GoogleTests/Models/HelmetTest.cpp
        GoogleTests/Models/RingTest.cpp
        Models/Ring.h
        Models/Ring.cpp
        GoogleTests/Models/ArmorTest.cpp
        Models/Armor.cpp
        Models/Armor.h
        GoogleTests/Models/FighterTest.cpp
        Models/fighter.cpp
        Models/fighter.h
        GoogleTests/Models/DiceTest.cpp
        Models/Dice.h
        Models/Dice.cpp
        GoogleTests/Models/BeltTest.cpp
        Models/Belt.cpp
        Models/Belt.h
        GoogleTests/Models/MapTest.cpp
        Models/Map.cpp
        Models/Map.h
        GoogleTests/Models/BootsTest.cpp
        Models/Boots.cpp
        Models/Boots.h
        GoogleTests/Models/WeaponTest.cpp
        Models/Weapon.cpp
        Models/Weapon.h
        GoogleTests/Models/ShieldTest.cpp
        Models/Shield.h
        Models/Shield.cpp
        GoogleTests/Models/ShieldTest.cpp
        Models/GameLog.h
        Models/GameController.h
        Models/MapBuilder.h
)
add_executable(UnitTests ${unitTestFiles}
        Models/MapBuilder.h) # add this executables

target_link_libraries(UnitTests PRIVATE gtest) # link google test to this executable
include(googletest)
gtest_discover_tests(UnitTests) # discovers tests by asking the compiled test executable to enumerate its tests

# include cereal library to serialize some classes
include_directories(Cereal/include)