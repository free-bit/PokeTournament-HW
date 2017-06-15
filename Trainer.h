#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include <vector>

#include "Pokemon.h"
#include "PokeFire.h"
#include "PokeWater.h"
#include "PokeGrass.h"
#include "PokeElectric.h"
#include "PokeFlying.h"

class Trainer
{
public:
	Trainer(int trainerID, const std::string& name, Arena favoriteArena, std::vector<Pokemon *>& pokemons);
	~Trainer();

	// Getters
	int getTrainerID() const;
	const std::string& getName() const;
	Arena getFavoriteArena() const;

	//Helpers for pokemons list
	int getSize();
	Pokemon* getPokemonAt(int i);
	void restoreAllPokemons();
	void show();

private:
	int trainerID; 		// Unique
	std::string name;
	Arena favoriteArena;

	std::vector<Pokemon *> pokemons;//Apply shallow copy
};
#endif
