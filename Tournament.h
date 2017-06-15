#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Trainer.h"

#include <vector>

class Tournament
{
public:
	Tournament(const std::string& tName);
	~Tournament();

	// Trainer count will always be 2^n.
    void registerTrainers(const std::vector<Trainer*>& trainers);
    
    // Commence the tournament, and return the champion.
	Trainer* commence();

	// Return 1 if Trainer1 wins.
	// Return -1 if Trainer2 wins.
	// It may be called from main.cpp, aside from a Tournament.
	int duelBetween(Trainer* trainer1, Trainer* trainer2, Arena currentArena);

    // Getters
    const std::string& getTournamentName() const;

	//Helpers for trainer list
	int getSize();
	Trainer* getFront();
	Trainer* getBack();
	void removeFront();
	void removeBack();
	
private:
	std::string tournamentName;

	// Return 1 if Pokemon1 wins.
	// Return -1 if Pokemon2 wins.
	int duelBetween(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena);

	vector<Trainer*> lst;
};

#endif
