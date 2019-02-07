#include <iostream>
#include "Functions.hpp"
#include <stdlib.h>
#include <time.h>

void ResetMap(Map<std::uint16_t> &map)
{
    // Local helper function to reset all non treasure positions on the map to the maximum value
    // so that updateposition can then give them their correct values based on the remaining treasures
    for (long long unsigned int i = 0; i < map.size(); i++)
    {
        for (long long unsigned int j = 0; j < map.size(); j++)
        {
            if (map[j][i] != 0)
            {
                map[j][i] = map.size();
            }
        }
    }
}

void UpdateFromPosition(Map<std::uint16_t> &map, std::uint16_t xPos, std::uint16_t yPos)
{
    // Local helper function to update the map based on a specific position indicated by xPos and yPos
    for (long long unsigned int i = 0; i < map.size(); i++)
    {
        for (long long unsigned int j = 0; j < map.size(); j++)
        {
            if (map[j][i] != 0)
            {
            }
        }
    }
}

void CreateMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces, std::uint16_t width, std::uint16_t height)
{
    srand(time(NULL));

    for (long long unsigned int i = 0; i < width; i++)
    {
        map.emplace_back();
        takenSpaces.emplace_back();

        for (long long unsigned int j = 0; j < height; j++)
        {
            map.back().push_back(1);
            takenSpaces.back().push_back(false);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        int x = rand() % width;
        int y = rand() % height;
        map[y][x] = 0;
    }
    UpdateMap(map);
}

void UpdateMap(Map<std::uint16_t> &map)
{
    ResetMap(map);
    for (long long unsigned int xPos = 0; xPos < map.size(); xPos++)
    {
        for (long long unsigned int yPos = 0; yPos < map.size(); yPos++)
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
    for (long long unsigned int i = 0; i < map.size(); i++)
    {
        for (long long unsigned int j = 0; j < map.size(); j++)
        {
            if (takenSpaces[j][i] == true)
            {
                std::cout << map[j][i] << " ";
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
    Coordinate *coords = new Coordinate;
    std::cout << "type a number X: ";
    std::cin >> coords->x;
    std::cout << "type a number Y: ";
    std::cin >> coords->y;
    return *coords;
}