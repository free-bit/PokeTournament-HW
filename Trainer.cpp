#include "Trainer.h"

Trainer::Trainer(int trainerID, const std::string& name, Arena favoriteArena, std::vector<Pokemon *>& pokemons):
trainerID(trainerID),name(name),favoriteArena(favoriteArena),pokemons(pokemons)
{}

Trainer::~Trainer()
{
	std::vector<Pokemon *>::iterator it;
	for(it=pokemons.begin(); it!=pokemons.end(); it++)
		delete (*it);
	pokemons.clear();
}

int Trainer::getTrainerID() const
{
	return trainerID;
}

const std::string& Trainer::getName() const
{
	return name;
}

Arena Trainer::getFavoriteArena() const
{
	return favoriteArena;
}

int Trainer::getSize()
{
	return pokemons.size();
}

Pokemon* Trainer::getPokemonAt(int i)
{
	if(i>=pokemons.size())
		return NULL;//Indicates invalid index
	return pokemons[i];
}

void Trainer::restoreAllPokemons()
{
	vector<Pokemon *>::iterator it;
	for(it=pokemons.begin(); it!=pokemons.end(); it++)
		(*it)->restore();
}

void Trainer::show()
{
	cout<<getName()<<", No of Pokemon: "<<getSize()<<"\n";
	vector<Pokemon *>::iterator it;
	for(it=pokemons.begin(); it!=pokemons.end(); it++)
		cout<<"\t Pokemon Name: "<<(*it)->getName()<<"\n";
}