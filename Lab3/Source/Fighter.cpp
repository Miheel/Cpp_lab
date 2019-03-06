#undef new

#include "Fighter.hpp"
#include "MemoryLeakChecker.hpp"

Fighter::Fighter(const FighterData &fighterdata, std::string spriteFilemane, float spriteX, float spriteY) : sprite(spriteFilemane, spriteX, spriteY)
{

	this->Fdata.currentHealth = fighterdata.currentHealth;
	this->Fdata.defence = fighterdata.defence;
	this->Fdata.maxHealth = fighterdata.maxHealth;
	this->Fdata.name = fighterdata.name;
	this->Fdata.power = fighterdata.power;
	this->Fdata.speed = fighterdata.speed;
	this->Fdata.type = fighterdata.type;

	this->NrOfArr = 0;
	this->AList = nullptr;
}

Fighter::Fighter(const Fighter &other) : sprite(other.GetSprite())
{
	this->copy(other);
}

Fighter &Fighter::operator=(const Fighter &other)
{
	if (this != &other)
	{
		this->Fdata.currentHealth = other.Fdata.currentHealth;
		this->Fdata.defence = other.Fdata.defence;
		this->Fdata.maxHealth = other.Fdata.maxHealth;
		this->Fdata.name = other.Fdata.name;
		this->Fdata.power = other.Fdata.power;
		this->Fdata.speed = other.Fdata.speed;
		this->Fdata.type = other.Fdata.type;

		this->NrOfArr = other.NrOfArr;
	}
	if(other.AList.Check())
	{
		this->AList.reset(other.AList.Get());
	}
	else
	{
		this->AList = nullptr;
	}
	
	return *this;
}

const Sprite &Fighter::GetSprite() const
{
	return this->sprite;
}

std::uint8_t Fighter::GetNrOfAttacks() const
{
	return this->NrOfArr;
}

const FighterData &Fighter::GetFighterData() const
{
	return this->Fdata;
}

void Fighter::AddAttack(std::string filename)
{
	std::string file[5];
	std::ifstream inf;
	inf.open(filename, std::ifstream::in);

	UniqPtr temp(new Attack[this->NrOfArr + 1]);
	for (int i = 0; i < this->NrOfArr; i++)
	{
		temp.Get()[i] = this->AList.Get()[i];
	}
	this->NrOfArr += 1;
	this->AList = std::move(temp);

	for (int i = 0; i < 5; i++)
	{
		std::getline(inf, file[i]);
	}
	this->AList.Get()[this->NrOfArr - 1].name = file[0];
	this->AList.Get()[this->NrOfArr - 1].type = std::stoi(file[1]);
	this->AList.Get()[this->NrOfArr - 1].amount = std::stoi(file[2]);
	this->AList.Get()[this->NrOfArr - 1].speedPriority = std::stoi(file[3]);
	this->AList.Get()[this->NrOfArr - 1].text = file[4];
}

void Fighter::SetCurrentHealth(std::uint16_t amount)
{
	this->Fdata.currentHealth = amount;
}

const Attack &Fighter::operator[](std::uint8_t index) const
{
	return AList.Get()[index];
}

Fighter::~Fighter()
{
}

void Fighter::copy(const Fighter &other)
{
	this->Fdata.currentHealth = other.Fdata.currentHealth;
	this->Fdata.defence = other.Fdata.defence;
	this->Fdata.maxHealth = other.Fdata.maxHealth;
	this->Fdata.name = other.Fdata.name;
	this->Fdata.power = other.Fdata.power;
	this->Fdata.speed = other.Fdata.speed;
	this->Fdata.type = other.Fdata.type;

	this->NrOfArr = other.NrOfArr;

	UniqPtr AList(new Attack[this->NrOfArr]);
	for (int i = 0; i < other.NrOfArr; i++)
	{
		this->AList.Get()[i] = other.AList.Get()[i];
	}
}
