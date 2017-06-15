#ifndef POKEFIRE_H
#define POKEFIRE_H

#include "Pokemon.h"

class PokeFire : public Pokemon
{
public:
	PokeFire(int ID, const std::string& pokemonName);
	~PokeFire();

	void attackTo(Pokemon* target, Arena currentArena);
	void levelUp();
	void getDamage();
	void buff(string arena);

	// Getters 
	//Implemented in Pokemon.h
	//int getPokemonID() const;
	//const std::string& getName() const;
	//int getHP() const;
	//int getATK() const;
	//int getMAG_DEF() const;
	//int getPHY_DEF() const;
	//bool isBurning() const;
	//bool isDrowning() const;
	//bool isElectrified() const;
	//bool isRooted() const;

	// Setters
	void setBurning(bool burning);
	void setDrowning(bool drowning);
	void setElectrified(bool electrified);
	void setRooted(bool rooted);
};

#endif