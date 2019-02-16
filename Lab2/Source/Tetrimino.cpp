#include "Tetrimino.hpp"
#include <cmath>
#include <iostream>
int16_t SignOF(int16_t N)
{
	if (N < 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

Block::Coordinates RotateCoordinates(Block::Coordinates coordinates, float cosinusRotation, float sinusRotation)
{
	Block::Coordinates rotatedCords;
	rotatedCords.xCoord = coordinates.xCoord*cosinusRotation - coordinates.yCoord*sinusRotation;
	rotatedCords.yCoord = coordinates.xCoord*sinusRotation + coordinates.yCoord*cosinusRotation;
	return rotatedCords;
}

Block::Coordinates NewCenterCoordinates(Block::Coordinates coordinates, Block::Coordinates figureCenterCoordinates)
{
	Block::Coordinates newc;
	newc.xCoord = coordinates.xCoord + figureCenterCoordinates.xCoord;
	newc.yCoord = coordinates.yCoord + figureCenterCoordinates.yCoord;
	return newc;
}

int16_t SnapToGrid(int16_t coordinate, uint16_t blockSideLength)
{
	int16_t centerCoord = std::abs(coordinate) + blockSideLength / 2;
	int16_t topLeft = (centerCoord / blockSideLength)*blockSideLength;
	return SignOF(coordinate)*topLeft;
}

Tetrimino::Tetrimino()
{
}

Tetrimino::Tetrimino(std::vector<Block::Coordinates> blockPositions, Block::Coordinates blockCenter, Colour blockColour)
{
	this->centerPoint = blockCenter;
	for (size_t i = 0; i < blockPositions.size(); i++)
	{
		Block block = Block(blockPositions[i], BLOCKSIZE, Block::RGBValues({ blockColour.r, blockColour.g, blockColour.b }), 0);
		this->blocks.push_back(block);
	}
}

void Tetrimino::Rotate(float radians)
{	
	Block::Coordinates shiftedCoords;
	Block::Coordinates topLeft;
	Block::Coordinates newCoords;
	Block::Coordinates figcenter = this->centerPoint;
	float sinRotate = std::sin(radians);
	float cosRotate = std::cos(radians);

	for (size_t i = 0; i < blocks.size(); i++)
	{
		shiftedCoords.xCoord = blocks[i].GetCoordinates().xCoord + blocks[i].GetSize() / 2 - figcenter.xCoord;
		shiftedCoords.yCoord = blocks[i].GetCoordinates().yCoord + blocks[i].GetSize() / 2 - figcenter.yCoord;
		
		Block::Coordinates rotated = RotateCoordinates(shiftedCoords, cosRotate, sinRotate);
		
		Block::Coordinates newCenter = NewCenterCoordinates(rotated, figcenter);
		
		topLeft.xCoord = newCenter.xCoord - blocks[i].GetSize() / 2;
		topLeft.yCoord = newCenter.yCoord - blocks[i].GetSize() / 2;

		newCoords.xCoord = SnapToGrid(topLeft.xCoord, blocks[i].GetSize());
		newCoords.yCoord = SnapToGrid(topLeft.yCoord, blocks[i].GetSize());
		blocks[i].SetCoordinates(newCoords);
	}
}

void Tetrimino::Move(Direction dir)
{
	switch (dir)
	{
	case Direction::DOWN:
		for (size_t i = 0; i < blocks.size(); i++)
		{
			blocks[i].Move(0, blocks[i].GetSize());

		}
		
		this->centerPoint.yCoord += BLOCKSIZE;
		break;
	
	case Direction::LEFT:
		for (size_t i = 0; i < blocks.size(); i++)
		{
			blocks[i].Move(-blocks[i].GetSize(), 0);
		}
		
		this->centerPoint.xCoord -= BLOCKSIZE;
		break;
	
	case Direction::RIGHT:
		for (size_t i = 0; i < blocks.size(); i++)
		{
			blocks[i].Move(blocks[i].GetSize(), 0);
		}
		
		this->centerPoint.xCoord += BLOCKSIZE;
		break;
	
	case Direction::UP:
		for (size_t i = 0; i < blocks.size(); i++)
		{
			blocks[i].Move(0, -blocks[i].GetSize());
		}
		break;
	
	default:
		break;
	}
}

bool Tetrimino::CheckCollision(const Block & otherBlocks) const
{
	bool checkcol = false;
	for (size_t i = 0; i < blocks.size(); i++)
	{
		if (otherBlocks.GetCoordinates().xCoord  == blocks[i].GetCoordinates().xCoord && otherBlocks.GetCoordinates().yCoord == blocks[i].GetCoordinates().yCoord)
		{
			checkcol = true;
		}
	}
	return checkcol;
}

std::vector<Block> Tetrimino::GetBlocks() const
{
	return this->blocks;
}

int16_t Tetrimino::GetLeftEdge()
{
	int left = this->centerPoint.xCoord;
	for (size_t i = 0; i < this->blocks.size(); i++)
	{
		if (left > blocks[i].GetCoordinates().xCoord)
		{
			left = blocks[i].GetCoordinates().xCoord;
		}
	}
	return left;
}

int16_t Tetrimino::GetRightEdge()
{
	int right = this->centerPoint.xCoord;
	for (size_t i = 0; i < this->blocks.size(); i++)
	{
		if (right < blocks[i].GetCoordinates().xCoord + blocks[i].GetSize())
		{
			right = blocks[i].GetCoordinates().xCoord + blocks[i].GetSize();
		}
	}
	return right;
}

int16_t Tetrimino::GetBottomEdge()
{
	int bottom = this->centerPoint.yCoord;
	for (size_t i = 0; i < blocks.size(); i++)
	{
		if (bottom < blocks[i].GetCoordinates().yCoord + blocks[i].GetSize())
		{
			bottom = blocks[i].GetCoordinates().yCoord + blocks[i].GetSize();
		}
	}
	return bottom;
}
