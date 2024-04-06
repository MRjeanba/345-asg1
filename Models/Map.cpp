// Importations
#include "Map.h"
#include "MapObserver.cpp"
#include <iostream>
#include <queue>
#include <stdexcept>

// SingleCell constructor
SingleCell::SingleCell() : type(CellType::Empty) {}

/**
 * @brief Sets the type of the cell.
 *
 * @param givenType The type of the cell.
 */
void SingleCell::setType(CellType givenType)
{
    type = givenType;
}

/**
 * @brief Gets the type of the cell.
 *
 * @return The type of the cell.
 */
CellType SingleCell::getType() const
{
    return type;
}

// Map constructor
Map::Map(int w, int h) : width(w), height(h), grid(h, std::vector<SingleCell>(w)) {}

Map::Map() : width(0), height(0), grid() {}

/**
 * @brief Sets the type of the cell at the given coordinates.
 *
 * @param i The x-coordinate of the cell.
 * @param j The y-coordinate of the cell.
 * @param type The type of the cell.
 */
void Map::setCellType(int i, int j, CellType type)
{
    if (i >= 0 && i < width && j >= 0 && j < height)
    {
        grid[i][j].setType(type);
    }
}

/**
 * @brief Gets the type of the cell at the given coordinates.
 *
 * @param i The x-coordinate of the cell.
 * @param j The y-coordinate of the cell.
 * @return The type of the cell.
 * @throw std::out_of_range If the coordinates are out of range.
 */
CellType Map::getCellType(int i, int j) const
{
    if (i >= 0 && i < width && j >= 0 && j < height)
    {
        return grid[i][j].getType();
    }
    throw std::out_of_range("Coordinates out of range");
}

/**
 * @brief Validates the map to ensure there is a clear path between the specified start and end cells.
 *
 * Uses breadth-first search (BFS) to search for a clear path.
 *
 * @param begin_i The x-coordinate of the start cell.
 * @param begin_j The y-coordinate of the start cell.
 * @param end_i The x-coordinate of the end cell.
 * @param end_j The y-coordinate of the end cell.
 * @return True if a clear path exists, false otherwise.
 */
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

int Map::getHeight()
{
    return this->height;
}

int Map::getWidth()
{
    return this->width;
}


void Map::displayMap() {
    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            switch (grid[j][i].getType()) {
                case CellType::Empty:
                    std::cout << "■";
                    break;
                case CellType::Wall:
                    std::cout << "#";
                    break;
                case CellType::Character: // Display "@" for character
                    std::cout << "@";
                    break;
                case CellType::ValidTarget: // Display green coloured cell for valid target area
                    std::cout << "\033[1;31m■\033[0m";
                    break;
                case CellType::Cursor: // Display arrow dot for cursor
                    std::cout << "△";
                    break;
                case CellType::End: // Display "X" for end cell
                    std::cout << "X";
                    break;
                default:
                    std::cout << "?"; // Unknown cell type
                    break;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Map ::registerObserver(MapObserver *observer)
{
    observers.push_back(observer);
    std::cout << "Observer registered. \n";
};

void Map ::unregisterObserver(MapObserver *observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
    {
        observers.erase(it);
        std::cout << "Observer unregistered. \n";

        if (it != observers.end())
        {
            observers.erase(std::remove(observers.begin(), observers.end(), observers.back()), observers.end());
        }
    }
};

void Map ::notifyObservers()
{
    std::cout << "All observers of the map have been updated. \n";
    std::cout << "Display of the updated map:  \n";
    this->displayMap();
};

void Map::recordMovement(const std::string& movement)
{
    Observable::notifyObservers("Movement on map: " + movement);
}