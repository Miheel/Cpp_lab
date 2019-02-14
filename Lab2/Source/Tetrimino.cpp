#include "Tetrimino.hpp"
#include <cmath>
#include <iostream>
int16_t Tetrimino::SignOF(Block::Coordinates N)
{
	if (N.xCoord < 0 && N.yCoord < 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

Block::Coordinates Tetrimino::RotateCoordinates(Block::Coordinates coordinates, float cosinusRotation, float sinusRotation)
{
	Block::Coordinates rotatedCords;
	rotatedCords.xCoord = coordinates.xCoord*cosinusRotation - coordinates.yCoord*sinusRotation;
	rotatedCords.yCoord = coordinates.yCoord*sinusRotation + coordinates.xCoord*cosinusRotation;
	return rotatedCords;
}

Block::Coordinates Tetrimino::NewCenterCoordinates(Block::Coordinates coordinates, Block::Coordinates figureCenterCoordinates)
{
	coordinates.xCoord = coordinates.xCoord + figureCenterCoordinates.xCoord;
	coordinates.yCoord = coordinates.yCoord + figureCenterCoordinates.yCoord;
	return coordinates;
}

int16_t Tetrimino::SnapToGrid(Block::Coordinates coordinate, uint8_t blockSideLength)
{
	Block::Coordinates centerCoords;
	Block::Coordinates topLeft;
	centerCoords.xCoord = std::abs(coordinate.xCoord) + blockSideLength / 2;
	centerCoords.yCoord = std::abs(coordinate.yCoord) + blockSideLength / 2;
	topLeft.xCoord = (centerCoords.xCoord / BLOCKSIZE)*blockSideLength;
	topLeft.yCoord = (centerCoords.yCoord / BLOCKSIZE)*blockSideLength;
	return ;
}



Tetrimino::Tetrimino()
{
}

Tetrimino::Tetrimino(std::vector<Block::Coordinates> blockPositions, Block::Coordinates blockCenter, Colour blockColour)
{
	this->centerPoint = blockCenter;
	for (size_t i = 0; i < blocks.size(); i++)
	{
		this->blocks.push_back(Block());
		Block(blockPositions, uint16_t(10), Block::RGBValues({ 255, 255, 255 }), uint16_t(0));
	}
}

void Tetrimino::Rotate(float radians)
{
	Block::Coordinates topLeft;
	Block::Coordinates shiftedCoords;
	float sinRotate = std::sin(radians);
	float cosRotate = std::cos(radians);
	Block::Coordinates figcenterCoords = centerPoint;

	for (auto &Block : blocks)
	{
		shiftedCoords.xCoord = Block.GetCoordinates().xCoord + Block.GetSize() / 2 - figcenterCoords.xCoord;
		shiftedCoords.yCoord = Block.GetCoordinates().yCoord + Block.GetSize() / 2 - figcenterCoords.yCoord;
		Block::Coordinates rotated = RotateCoordinates(shiftedCoords, cosRotate, sinRotate);
		Block::Coordinates newCenter = NewCenterCoordinates(rotated, figcenterCoords);
		topLeft.xCoord = newCenter.xCoord - Block.GetSize() / 2;
		topLeft.yCoord = newCenter.yCoord - Block.GetSize() / 2;

		Block.SetCoordinates(SnapToGrid(topLeft.xCoord, Block.GetSize()));
		Block.SetCoordinates(SnapToGrid(topLeft.yCoord, Block.GetSize()));
	}
	std::cout << "n";
}

void Tetrimino::Move(Direction dir)
{
}

bool Tetrimino::CheckCollision(const Block & otherBlocks) const
{
	return false;
}

std::vector<Block> Tetrimino::GetBlocks() const
{
	return std::vector<Block>();
}

int16_t Tetrimino::GetLeftEdge()
{
	return Block().GetCoordinates().xCoord;
}

int16_t Tetrimino::GetRightEdge()
{
	return Block().GetCoordinates().xCoord + Block().GetSize();
}

int16_t Tetrimino::GetBottomEdge()
{
	return Block().GetCoordinates().yCoord + Block().GetSize();
}
