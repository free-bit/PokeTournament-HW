#ifndef TRAINER_CENTER_H
#define TRAINER_CENTER_H

#include "Trainer.h"
#include "Pokemon.h"

#include <vector>
#include <string>

#include <fstream>
#include <cstdlib>

class TrainerCenter
{
public:
	TrainerCenter(const std::string& inputFileName);
    ~TrainerCenter();
    
	std::vector<Trainer*>& getAllTrainers();

	Trainer* getTrainerWithID(int trainerID);

private:
	//Members
	const char* name;
	vector<Trainer*> trainerlst;
	
	//Member functions
	Arena convertArena(string arena);
	int stoi(string s);
};

#endif
