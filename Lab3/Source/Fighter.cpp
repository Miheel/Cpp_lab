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

	this->NrOfATK = 1;
	this->AList = new UniqPtr[this->NrOfATK];
}

Fighter::Fighter(const Fighter &other) : sprite(other.GetSprite())
{
	this->copy(other);
}

Fighter &Fighter::operator=(const Fighter &other)
{
	if (this != &other)
	{
		this->copy(other);
	}

	return *this;
}

const Sprite &Fighter::GetSprite() const
{
	return this->sprite;
}

std::uint8_t Fighter::GetNrOfAttacks() const
{
	return this->NrOfATK;
}

const FighterData &Fighter::GetFighterData() const
{
	return this->Fdata;
}

void Fighter::AddAttack(std::string filename)
{
	//open an atk file and load each line in a string arr
	//each member in an attack object is then assigned a value from the string arr
	//the internal arr Alist is then checked if it is full and neads to be expanded
	//the Attack object if then fitted into the last place of the Alist arr
	std::string file[5];
	std::ifstream inf;
	inf.open(filename, std::ifstream::in);

	for (int i = 0; i < 5; i++)
	{
		std::getline(inf, file[i]);
	}

	Attack *atkObj = new Attack();
	(*atkObj).name = file[0];
	(*atkObj).type = std::stoi(file[1]);
	(*atkObj).amount = std::stoi(file[2]);
	(*atkObj).speedPriority = std::stoi(file[3]);
	(*atkObj).text = file[4];

	if (this->AList->Check())
	{
		this->expand();
	}

	this->AList[this->NrOfATK - 1].reset(atkObj);

	inf.close();
}

void Fighter::SetCurrentHealth(std::uint16_t amount)
{
	this->Fdata.currentHealth = amount;
}

const Attack &Fighter::operator[](std::uint8_t index) const
{
	return *AList[index];
}

Fighter::~Fighter()
{
	this->freemem();
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

	this->NrOfATK = other.NrOfATK;

	this->AList = new UniqPtr[other.NrOfATK];
	for (int i = 0; i < other.NrOfATK; i++)
	{
		this->AList[i].reset(new Attack(other[i]));
	}
}

void Fighter::expand()
{
	//expanding of the internal arr
	//create a new temp arr "temp" with bigger size
	//loop over the internal arr and give temp the elements
	//assign the internal arr the newly constructed temp arr
	this->NrOfATK += 1;
	UniqPtr *temp = new UniqPtr[this->NrOfATK];
	for (int i = 0; i < this->NrOfATK - 1; i++)
	{
		temp[i].reset(new Attack(*this->AList[i]));
	}
	this->freemem();
	this->AList = temp;
}

void Fighter::freemem() const
{
	delete[] this->AList;
}