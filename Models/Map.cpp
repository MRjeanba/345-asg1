// Importations
#include "Map.h"
#include <queue>
#include <stdexcept>

// SingleCell constructor
SingleCell::SingleCell() : type(CellType::Empty) {}

// SingleCell Set Member function
void SingleCell::setType(CellType givenType)
{
    type = givenType;
}

// SingleCell Get Member function
CellType SingleCell::getType() const
{
    return type;
}

// Map constructor
Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<SingleCell>(w)) {}

// Map Member Function
void Map::setCellType(int i, int j, CellType type)
{
    if (i >= 0 && i < width && j >= 0 && j < height)
    {
        grid[i][j].setType(type);
    }
}

CellType Map::getCellType(int i, int j) const
{
    if (i >= 0 && i < width && j >= 0 && j < height)
    {
        return grid[i][j].getType();
    }
    throw std::out_of_range("Coordinates out of range");
}

bool Map::isValidMap(int begin_i, int begin_j, int end_i, int end_j) const
{
    // Use BFS to check for path
    std::queue<std::pair<int, int>> searchQueue;
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

    searchQueue.push({begin_i, begin_j});
    visited[begin_j][begin_i] = true;

    // To represent movement left, right, up, down
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!searchQueue.empty())
    {
        auto [current_x, current_y] = searchQueue.front(); // Retrieve cell
        searchQueue.pop();                                 // Cell is visited, pop it

        if (current_x == end_i && current_y == end_j)
        {
            return true; // Found a path from start to end
        }

        for (int i = 0; i < 4; ++i)
        {
            // Search neighbouring cells
            int nx = current_x + dx[i];
            int ny = current_y + dy[i];

            if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
                !visited[ny][nx] && grid[ny][nx].getType() != CellType::Wall) // Verify that cell exists & has not been visited
            {
                searchQueue.push({nx, ny}); // If cell exists, add to search queue
                visited[ny][nx] = true;     // Mark it as visited
            }
        }
    }

    return false; // No path between begin and end cell
}
