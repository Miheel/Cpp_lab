//Fil for implementation of the main-function
#include <iostream>
#include <string>
#include "Functions.hpp"

int main()
{
    Map<std::uint16_t> map;
    Map<bool> booleanMap;
	int TreasureFound = 0;
	int moveCounter = 0;
    Coordinate input;
	std::uint16_t height = 10;
	std::uint16_t width = 10;

    CreateMap(map, booleanMap, width, height);

    while (TreasureFound < 3)
    {
        PrintMap(map, booleanMap);
        input = InputCoordinates();

		if (!std::cin.fail() && input.x < map[0].size() && input.y < map.size() && input.x >= 0 && input.y >= 0 && booleanMap[input.y][input.x] == false)
		{
			if (map[input.y][input.x] == 0)
			{
				map[input.y][input.x] = map.size();
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
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInvalid input";	
			getchar();
		}
    }

	std::cout << "it took you " << moveCounter << " tries to win";
    getchar();

    return 0;
}