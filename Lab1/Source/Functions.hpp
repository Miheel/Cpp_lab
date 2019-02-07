#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <cctype>
#include <cstdint>
#include <limits>
#include <cmath>

template <typename T>
using Column = std::vector<T>;
template <typename T>
using Map = std::vector<Column<T>>;

struct Coordinate
{
    std::uint16_t x;
    std::uint16_t y;
};

void CreateMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces, std::uint16_t width, std::uint16_t height);
void UpdateMap(Map<std::uint16_t> &map);
void PrintMap(Map<std::uint16_t> &map, Map<bool> &takenSpaces);
Coordinate InputCoordinates();

#endif