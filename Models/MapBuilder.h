#ifndef MAPBUILDER_H
#define MAPBUILDER_H

#include <iostream>
#include <string>
#include <Map.cpp>

// Builder interface
class MapBuilder
{
public:
    virtual void buildMap(string filename) = 0;
    Map mapToFill;
    virtual ~MapBuilder(){};
    MapBuilder(string filename);
};

// ConcreteBuilder 1: For the map editor
class MapFromTextFile : public MapBuilder
{
private:
    Map *map;
    Map mapToFill;

public:
    void buildMap(string filename) override;
    MapFromTextFile(Map *map) : map(map){};
};

// ConcreteBuilder 2: For game play, adapting characters and items
class MapGamePlayBuilder : public MapBuilder
{
private:
    Map *map;
    int level;

public:
    MapGamePlayBuilder(Map *map, int level) : map(map), level(level){};
    void buildMap(string filename) override;
};

#endif