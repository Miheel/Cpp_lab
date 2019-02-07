//Fil for implementation of the main-function
#include <iostream>
#include "Functions.hpp"

int main()
{
    Map<std::uint16_t> map;
    Map<bool> booleanMap;
    int TreasureFound = 0;
    Coordinate *input = new Coordinate;

    CreateMap(map, booleanMap, 10, 10);

    while (TreasureFound < 3)
    {
        PrintMap(map, booleanMap);
        *input = InputCoordinates();
        
        if (map[input->x][input->y] == 0)
        {
            map[input->x][input->y] = map.size();
            UpdateMap(map);
            std::cout << "You found a treasure!" << std::endl;
            TreasureFound++;
            getchar();
        }
        
        booleanMap[input->x][input->y] = true;

        //clear screen;
    }
    getchar();

    return 0;
}