#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <string>
#include <fstream>
#include "Attack.hpp"
#include "Sprite.hpp"
#include "UniquePointer.hpp"

#include "MemoryLeakChecker.hpp"

struct FighterData
{
    std::string name;
    std::uint8_t type;
    std::uint16_t maxHealth;
    std::uint16_t currentHealth;
    std::uint16_t power;
    std::uint16_t defence;
    std::uint16_t speed;
};

class Fighter
{
public:
	Fighter(const FighterData& fighterdata, std::string spriteFilemane, float spriteX, float spriteY);
	Fighter(const Fighter& other);
	Fighter& operator=(const Fighter& other);

	const Sprite& GetSprite()const;
	std::uint8_t GetNrOfAttacks()const;
	const FighterData& GetFighterData()const;

	void AddAttack(std::string filename);
	void SetCurrentHealth(std::uint16_t amount);
	const Attack& operator[](std::uint8_t index)const;
	
	~Fighter();

private:
	Sprite sprite;
	int NrOfArr;
	FighterData Fdata;
	UniqPtr AList;

	void copy(const Fighter& other);
	void freeMem()const;

};
#endif