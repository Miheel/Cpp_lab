#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include "Functions.hpp"

void ResetMap(Map<std::uint16_t> &map)
{
    // Local helper function to reset all non treasure positions on the map to the maximum value
    // so that updateposition can then give them their correct values based on the remaining treasures
    const std::uint16_t maxValue = std::numeric_limits<std::uint16_t>::max();

    for (std::uint16_t yPos = 0; yPos < map.size(); yPos++)
    {
        for (std::uint16_t xPos = 0; xPos < map[0].size(); xPos++)
        {
            if (map[yPos][xPos] != 0)
            {
                map[yPos][xPos] = maxValue;
            }
        }
    }
}

void UpdateFromPosition(Map<std::uint16_t> &map, std::uint16_t xPos, std::uint16_t yPos)
{
    // Local helper function to update the map based on a specific position indicated by xPos and yPos
    int xLen = 0, yLen = 0, distanceFromTreasure = 0;

    for (std::uint16_t i = 0; i < map.size(); i++)
    {
        for (std::uint16_t j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] != 0)
            {
                //jump distance to find the distance of adjacent horizontal, vertical and diagonal places in the map
                xLen = abs(xPos - j);
                yLen = abs(yPos - i);

                distanceFromTreasure = std::max(xLen, yLen);

                if (distanceFromTreasure < map[i][j])
                {
                    map[i][j] = distanceFromTreasure;
                }
            }
        }
    }
}

void CreateMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces, std::uint16_t width, std::uint16_t height)
{
    //Creates a 2d vector based on with and height
    int x = 0, y = 0;

    map.resize(height, Column<std::uint16_t>(width, 1));
    takenSpaces.resize(height, Column<bool>(width, false));

    //Places 3 treasures on the map
    for (int i = 0; i < 3;)
    {
        x = rand() % width;
        y = rand() % height;

        if (map[y][x] != 0)
        {
            map[y][x] = 0;
            i++;
        }
    }

    UpdateMap(map);
}

void UpdateMap(Map<std::uint16_t> &map)
{
    //Finds the locatios of the treasures and calls for UpdateFromPosition at the pos of the treasures
    ResetMap(map);

    for (std::uint16_t yPos = 0; yPos < map.size(); yPos++)
    {
        for (std::uint16_t xPos = 0; xPos < map[0].size(); xPos++)
        {
            if (map[yPos][xPos] == 0)
            {
                UpdateFromPosition(map, xPos, yPos);
            }
        }
    }
}

void PrintMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces)
{
    for (std::uint16_t yPos = 0; yPos < map.size(); yPos++)
    {
        for (std::uint16_t xPos = 0; xPos < map[0].size(); xPos++)
        {
            if (takenSpaces[yPos][xPos] == true)
            {
                std::cout << " " << map[yPos][xPos] << " ";
            }

            else
            {
                std::cout << " * ";
            }
        }

        std::cout << std::endl;
    }
}

Coordinate InputCoordinates()
{
    Coordinate coords;
    std::cout << "type a number X: ";
    std::cin >> coords.x;

    std::cout << "type a number Y: ";
    std::cin >> coords.y;
    return coords;
}
