#include "Pokemon.h"

Pokemon::Pokemon(int ID, const std::string& pokemonName)
{
	pokemonID=ID;
	name=pokemonName;
}

Pokemon::~Pokemon()
{}

// Getters
int Pokemon::getPokemonID() const
{
	return pokemonID;
}

const std::string& Pokemon::getName() const
{
	return name;
}

int Pokemon::getHP() const
{
	return HP;
}

int Pokemon::getATK() const
{
	return ATK;
}

int Pokemon::getMAG_DEF() const
{
	return MAG_DEF;
}

int Pokemon::getPHY_DEF() const
{
	return PHY_DEF;
}

bool Pokemon::isBurning() const
{
	return burning;
}

bool Pokemon::isDrowning() const
{
	return drowning;
}

bool Pokemon::isElectrified() const
{
	return electrified;
}

bool Pokemon::isRooted() const
{
	return rooted;
}

// Setters
void Pokemon::setBurning(bool burning)
{
	this->burning=burning;
}

void Pokemon::setDrowning(bool drowning)
{
	this->drowning=drowning;
}

void Pokemon::setElectrified(bool electrified)
{
	this->electrified=electrified;
}

void Pokemon::setRooted(bool rooted)
{
	this->rooted=rooted;
}

void Pokemon::setHP(int newHP)
{
	HP=newHP;
}

void Pokemon::operator++(int null)
{
	HP+=100;
	ATK+=10;
}

void Pokemon::operator--(int null)
{
	HP-=100;
	ATK-=10;
}

void Pokemon::restore()
{
	HP=defHP;
	ATK=defATK;
	MAG_DEF=defMAG_DEF;
	PHY_DEF=defPHY_DEF;

	burning=false;
	drowning=false;
	electrified=false;
	rooted=false;
}