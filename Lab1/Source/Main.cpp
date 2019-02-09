//Fil for implementation of the main-function
#include <iostream>
#include <string>
#include <time.h>
#include "Functions.hpp"

int main()
{	
	const std::uint16_t maxValue = std::numeric_limits<std::uint16_t>::max();
	srand(static_cast<unsigned>(time(NULL)));

    Map<std::uint16_t> map;
    Map<bool> booleanMap;
    Coordinate input;

	std::uint16_t height = 10, width = 10;
	int TreasureFound = 0, moveCounter = 0;

    CreateMap(map, booleanMap, width, height);

    while (TreasureFound < 3)
    {
        PrintMap(map, booleanMap);
        input = InputCoordinates();

		if (!std::cin.fail() && input.x < map[0].size() && input.y < map.size() && input.x >= 0 && input.y >= 0 && booleanMap[input.y][input.x] == false)
		{
			if (map[input.y][input.x] == 0)
			{
				map[input.y][input.x] = maxValue;
				UpdateMap(map);
				std::cout << "You found a treasure!" << std::endl;
				TreasureFound++;
				getchar();
			}

			booleanMap[input.y][input.x] = true;
			moveCounter++;
		}

		else
		{			
			std::cout << "\nInvalid input";
			getchar();
		}
    }

	std::cout << "it took you " << moveCounter << " tries to win";
    getchar();

    return 0;
}