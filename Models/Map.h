#ifndef MAP_H
#define MAP_H

// Import libraries
#include <fstream>
#include <map>
#include <vector>
#include <cereal/archives/xml.hpp>
#include <cereal/types/vector.hpp>

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
    CellType type; /**< Type of the cell. */

public:
    /**
     * @brief Constructor for SingleCell class.
     *
     * Initializes the cell type to Empty.
     */
    SingleCell();

    /**
     * @brief Sets the type of the cell.
     *
     * @param newType The type of the cell
     */
    void setType(CellType newType);

    /**
     * @brief Gets the type of the cell.
     *
     * @return The type of the cell.
     */
    CellType getType() const;
 template<class Archive>
 void serialize(Archive & archive)
 {
  archive( type ); // serialize things by passing them to the archive
 }
};

/**
 * @brief Represents a grid map composed of cells.
 */
class Map
{
private:
    int width;                                 /**< Width of the map. */
    int height;                                /**< Height of the map. */
    std::vector<std::vector<SingleCell>> grid; /**< Grid of the map. */

public:
    /**
     * @brief Constructor for Map class.
     *
     * Initializes the map with the specified width and height.
     *
     * @param w The width of the map.
     * @param h The height of the map.
     */
    Map(int w, int h);

 explicit Map();

    /**
     * @brief Sets the type of the cell at the given coordinates.
     *
     * @param i The x-coordinate of the cell.
     * @param j The y-coordinate of the cell.
     * @param type The type of the cell to set.
     */
    void setCellType(int i, int j, CellType type);

    /**
     * @brief Gets the type of the cell at the given coordinates.
     *
     * @param i The x-coordinate of the cell.
     * @param j The y-coordinate of the cell.
     * @return The type of the cell.
     * @throw std::out_of_range If the coordinates are out of range.
     */
    CellType getCellType(int i, int j) const;

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
    bool isValidMap(int begin_i, int begin_j, int end_i, int end_j) const;

   int getHeight();
 // This method lets cereal know which data members to serialize
 template<class Archive>
 void serialize(Archive & archive)
 {
  archive( height, width, grid ); // serialize things by passing them to the archive
 }

};

inline void saveMap(Map& m, const std::string& filename) {
 std::ofstream os(std::filesystem::current_path() / "../" / filename);
 cereal::XMLOutputArchive archive(os);

 archive( m ); // store the current instance
}

inline void loadMap(Map& mapToFill, const std::string& filename) {
 std::ifstream is(std::filesystem::current_path() / "../" / filename);
 cereal::XMLInputArchive archive(is);
 archive(mapToFill);
}



#endif
