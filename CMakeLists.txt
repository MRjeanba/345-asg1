cmake_minimum_required(VERSION 3.28)
project(345_asg1)

set(CMAKE_CXX_STANDARD 17)
CXXFLAGS += -std=c++17

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
        Models/ItemContainer.cpp
        Models/ItemContainer.h)

#enable_testing() #to  discover tests in test explorer
#add_subdirectory(GoogleTests/lib/googletest)
#include_directories(GoogleTests/lib/googletest/include) # this is so we can #include <gtest/gtest.h>

#set(unitTestFiles
#        Models/Helmet.h
#        GoogleTests/driverTest.cpp
#        Models/Helmet.cpp
#        Models/Item.h
#        Models/Item.cpp
#        GoogleTests/Models/HelmetTest.cpp
#        GoogleTests/Models/RingTest.cpp
#        Models/Ring.h
#        Models/Ring.cpp
#        GoogleTests/Models/ArmorTest.cpp
#        Models/Armor.cpp
#        Models/Armor.h
#)
#add_executable(UnitTests ${unitTestFiles}) # add this executables
#
#target_link_libraries(UnitTests PRIVATE gtest) # link google test to this executable
#include(GoogleTest)
#gtest_discover_tests(UnitTests) # discovers tests by asking the compiled test executable to enumerate its tests

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
)
add_executable(UnitTests ${unitTestFiles}) # add this executables

target_link_libraries(UnitTests PRIVATE gtest) # link google test to this executable
include(GoogleTest)
gtest_discover_tests(UnitTests) # discovers tests by asking the compiled test executable to enumerate its tests