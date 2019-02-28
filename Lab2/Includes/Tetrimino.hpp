#ifndef TETRIMINOS_H
#define TETRIMINOS_H

#include "Block.hpp"
#include <vector>
#include <cstdint>

enum class Direction
{
    UP,
    LEFT,
    RIGHT,
    DOWN
};

struct Colour
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

class Tetrimino
{
private:
    std::vector<Block> blocks;
    Block::Coordinates centerPoint;

    int16_t SignOF(Block::Coordinates N);
    Block::Coordinates RotateCoordinates(Block::Coordinates coordinates, float cosinusRotation, float sinusRotation);
    Block::Coordinates NewCenterCoordinates(Block::Coordinates coordinates, Block::Coordinates figureCenterCoordinates);
    int16_t SnapToGrid(Block::Coordinates coordinate, uint8_t blockSideLength);

public:
    Tetrimino();
    Tetrimino(std::vector<Block::Coordinates> blockPositions, Block::Coordinates blockCenter, Colour blockColour);

    void Rotate(float radians);
    void Move(Direction dir);
    bool CheckCollision(const Block& otherBlocks) const;
    std::vector<Block> GetBlocks() const;
    int16_t GetLeftEdge();
    int16_t GetRightEdge();
    int16_t GetBottomEdge();


    static const uint8_t BLOCKSIZE = 40;
};

#endif