#include <gtest/gtest.h>
#include "../../Models/Map.h"

class MapTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        map = new Map(3, 3);
    }
    // Test Cleanup
    void tearDown()
    {
        delete map;
    }

    Map *map{};
};

// Test Set and Get Members
TEST_F(MapTest, SetGet_CellType)
{
    map->setCellType(1, 1, CellType::Wall);
    EXPECT_EQ(map->getCellType(1, 1), CellType::Wall);
}

// Test Map Validity for Clear Path
TEST_F(MapTest, ValidMapWithClearPath)
{
    map->setCellType(0, 0, CellType::Empty);
    map->setCellType(0, 1, CellType::Empty);
    map->setCellType(0, 2, CellType::Empty);
    map->setCellType(1, 2, CellType::Empty);
    map->setCellType(2, 2, CellType::Empty);

    EXPECT_TRUE(map->isValidMap(0, 0, 2, 2));
}

// Test Map Validity for Path that is not clear
TEST_F(MapTest, InvalidMapWithoutClearPath)
{
    map->setCellType(0, 0, CellType::Empty);
    map->setCellType(0, 1, CellType::Wall);
    map->setCellType(1, 1, CellType::Wall);
    map->setCellType(2, 1, CellType::Wall);
    map->setCellType(2, 2, CellType::Empty);
    EXPECT_FALSE(map->isValidMap(0, 0, 2, 2));
}