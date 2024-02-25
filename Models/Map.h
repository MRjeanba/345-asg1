#ifndef MAP_H
#define MAP_H

// Import libraries
#include <vector>

// Define Cell Types
enum class CellType
{
    Empty,
    Wall,
    Occupied
};

// Define single cell
class SingleCell
{
private:
    CellType type;

public:
    SingleCell();

    void setType(CellType newType);
    CellType getType() const;
};

// Define entire map
class Map
{
private:
    int width;
    int height;
    std::vector<std::vector<SingleCell>> grid;

public:
    Map(int w, int h);

    // Give the type to any cell
    void setCellType(int i, int j, CellType type);

    // Verify the validity of the map
    bool isValidMap(int begin_i, int begin_j, int end_i, int end_j) const;
};

#endif
