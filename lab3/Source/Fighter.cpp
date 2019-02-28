#include "Fighter.hpp"

Fighter::Fighter(const FighterData & fighterdata, std::string spriteFilemane, float spriteX, float spriteY): sprite(spriteFilemane, spriteX, spriteY)
{
	this->Fdata.currentHealth = fighterdata.currentHealth;
	this->Fdata.defence = fighterdata.defence;
	this->Fdata.maxHealth = fighterdata.maxHealth;
	this->Fdata.name = fighterdata.name;
	this->Fdata.power = fighterdata.power;
	this->Fdata.speed = fighterdata.speed;
	this->Fdata.type = fighterdata.type;

	this->NrOfArr = 1;
	this->AList = new UniqPtr[this->NrOfArr];
}

Fighter::Fighter(const Fighter & other):sprite(other.sprite)
{
	this->copy(other);
}

Fighter & Fighter::operator=(const Fighter & other)
{
	if (this != &other)
	{
		this->freeMem();
		this->copy(other);
	}
	return *this;
}

const Sprite & Fighter::GetSprite() const
{
	return ;
}

std::uint8_t Fighter::GetNrOfAttacks() const
{
	return std::uint8_t();
}

const FighterData & Fighter::GetFighterData() const
{
	return;
}

void Fighter::AddAttack(std::string filename)
{
}

void Fighter::SetCurrentHealth(std::uint16_t amount)
{
	this->Fdata.currentHealth = amount;
}

const Attack & Fighter::operator[](std::uint8_t index) const
{
	return;
}

Fighter::~Fighter()
{
}

void Fighter::copy(const Fighter & other)
{
	this->Fdata.currentHealth = other.Fdata.currentHealth;
	this->Fdata.defence = other.Fdata.defence;
	this->Fdata.maxHealth = other.Fdata.maxHealth;
	this->Fdata.name = other.Fdata.name;
	this->Fdata.power = other.Fdata.power;
	this->Fdata.speed = other.Fdata.speed;
	this->Fdata.type = other.Fdata.type;

	this->NrOfArr = other.NrOfArr;
	this->AList = new UniqPtr[other.NrOfArr];
	for (int i = 0; i < other.NrOfArr; i++)
	{
		this->AList[i] = new Attack(other[i]);
	}
}

void Fighter::freeMem() const
{
	delete[] this->AList;
}
