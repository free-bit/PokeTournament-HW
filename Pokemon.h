#ifndef POKEMON_H
#define POKEMON_H

#include <string>

#include "Enums.h"

#include <iostream>

#define DEFAULT 0

using namespace Helpers; //Using the definitions under "Helpers"

using namespace std;

class Pokemon
{
public:
	Pokemon(int ID, const std::string& pokemonName);
	~Pokemon();

	virtual void attackTo(Pokemon* target, Arena currentArena) = 0;	//pure
	virtual void levelUp() = 0;										//pure

	// Getters
	int getPokemonID() const;
	const std::string& getName() const;

	int getHP() const;
	int getATK() const;
	int getMAG_DEF() const;
	int getPHY_DEF() const;

	bool isBurning() const;
	bool isDrowning() const;
	bool isElectrified() const;
	bool isRooted() const;

	// Setters
	virtual void setBurning(bool burning);
	virtual void setDrowning(bool drowning);
	virtual void setElectrified(bool electrified);
	virtual void setRooted(bool rooted);
	void setHP(int newHP);

	virtual void getDamage()=0;//pure
	virtual void buff(string arena)=0;//pure, determines which buff to apply based on given arena
	void operator++(int null);//Overloaded post-fix increment
	void operator--(int null);//Overloaded post-fix decrement
	void restore();

protected:
	int pokemonID; 	// Unique

	std::string name;

	int HP;
	int ATK;
	int MAG_DEF;
	int PHY_DEF;

	bool burning;
	bool drowning;
	bool electrified;
	bool rooted;

	int defHP;
	int defATK;
	int defMAG_DEF;
	int defPHY_DEF;
};

#endif