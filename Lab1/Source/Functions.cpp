#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Functions.hpp"

void ResetMap(Map<std::uint16_t> &map)
{
    // Local helper function to reset all non treasure positions on the map to the maximum value
    // so that updateposition can then give them their correct values based on the remaining treasures
    for (std::uint16_t yPos = 0; yPos < map.size(); yPos++)
    {
        for (std::uint16_t xPos = 0; xPos < map[0].size(); xPos++)
        {
            if (map[yPos][xPos] != 0)
            {
                map[yPos][xPos] = static_cast<std::uint16_t>(map.size());
            }
        }
    }
}

void UpdateFromPosition(Map<std::uint16_t> &map, std::uint16_t xPos, std::uint16_t yPos)
{
    // Local helper function to update the map based on a specific position indicated by xPos and yPos
	int lenPoint = 0;
	int x1 = 0;
	int y1= 0;
    int x2 = 0;
	int y2 = 0;

    for (std::uint16_t i = 0; i < map.size(); i++)
    {
        for (std::uint16_t j = 0; j < map[0].size(); j++)
        {			    
			if (map[i][j] != 0)
			{
				//Finds the distance between the treasures and all the other point with the distance folmula
                x1 = i - yPos;
                y1 = j - xPos;

    			x2 = (int)std::pow(x1, 2);
    			y2 = (int)std::pow(y1, 2);

    			lenPoint = (int)std::sqrt(x2 + y2);

				if(map[i][j] > lenPoint)
				{						
					map[i][j] = lenPoint;
				}
			}		
        }
    }
}

void CreateMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces, std::uint16_t width, std::uint16_t height)
{
	//Creates a 2d vector based on with and height
	map.resize(height, Column<std::uint16_t>(width, 1));
	takenSpaces.resize(height, Column<bool>(width, false));
    /*for (std::uint16_t i = 0; i < height; i++)
    {
        map.emplace_back();
        takenSpaces.emplace_back();

        for (std::uint16_t j = 0; j < width; j++)
        {
            map.back().push_back(1);
            takenSpaces.back().push_back(false);
        }
    }*/

	//Places 3 treasures on the map 
    srand(static_cast<unsigned>(time(NULL)));
    for (int i = 0; i < 3;)
    {
        int x = rand() % width;
        int y = rand() % height;

		while (map[y][x] != 0)
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

const void erase()
{
#if defined _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void PrintMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces)
{
	//clears the screen and print out the map
	erase();

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

	std::cin.get();
    return coords;
}
