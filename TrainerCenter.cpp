#include "TrainerCenter.h"

TrainerCenter::TrainerCenter(const std::string& inputFileName)
{
	name=inputFileName.c_str();

	ifstream file;
	string line,trainername,arena,pokename,power,num;
	int id,index,index2,trainerNum,pokeNum,delim,delim2;
	Trainer* trainer;
	Pokemon* pokemon;
	vector<Pokemon *> pokemons;

	file.open(name);
  
	if(file.is_open())
  	{
  		getline(file,line);
  		index=line.find("Trainer Count:")+14;
      trainerNum=stoi(num.assign(line,index,line.length()-index));

      getline(file,line);
      index=line.find("Pokemon Count:")+14;
      pokeNum=stoi(num.assign(line,index,line.length()-index));

   		for(int i=0; i<trainerNum && !file.eof(); i++)
   		{
   			getline(file,line);

   			if(line=="")//Empty line skip
   			{
   				getline(file,line);
   			}

   			delim=line.find("--");
   			index=delim+2;

   			delim2=line.rfind("--");
   			index2=delim2+2;

   			id=stoi(num.assign(line,0,delim));
   			trainername.assign(line,index,delim2-index);
   			arena.assign(line,index2,line.length()-index2);

   			for(int j=0; j<pokeNum; j++)
   			{
   				getline(file,line);
   				delim=line.find("::");
   				index=delim+2;

   				delim2=line.rfind("::");
   				index2=delim2+2;
   				
				  id=stoi(num.assign(line,0,delim));
   				pokename.assign(line,index,delim2-index);
   				power.assign(line,index2,line.length()-index2);
   				
   				if(power=="FIRE" || power=="Fire")
   				{
   					pokemon=new PokeFire(id,pokename);
   				}

   				else if(power=="WATER" || power=="Water")
   				{
   					pokemon=new PokeWater(id,pokename);
   				}
   				
          else if(power=="ELECTRIC" || power=="Electric")
   				{
   					pokemon=new PokeElectric(id,pokename);
   				}
   				
          else if(power=="GRASS" || power=="Grass")
   				{
   					pokemon=new PokeGrass(id,pokename);
   				}
   				
          else if(power=="FLYING" || power=="Flying")
   				{
   					pokemon=new PokeFlying(id,pokename);
   				}
   				pokemons.push_back(pokemon);
   			}

   			trainer=new Trainer(id,trainername,convertArena(arena),pokemons);
   			trainerlst.push_back(trainer);
   			pokemons.clear();
   		}
  	}
  	file.close();
}

std::vector<Trainer*>& TrainerCenter::getAllTrainers()
{
	return trainerlst;
}

Trainer* TrainerCenter::getTrainerWithID(int trainerID)
{
	vector<Trainer*>::iterator it;
	for(it=trainerlst.begin(); it!=trainerlst.end(); it++)
	{
		if((*it)->getTrainerID()==trainerID)
			return *it;
	}
	return NULL;
}

int TrainerCenter::stoi(string s)
{
    int i, number=0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        number = 10 * number + (s[i]-'0');
    return number;
}

Arena TrainerCenter::convertArena(string arena)
{
	if(arena=="Stadium")
		return STADIUM;

	else if(arena=="Magma")
		return MAGMA;
	
  else if(arena=="Ocean")
		return OCEAN;
	
  else if(arena=="ElectriCity")
		return ELECTRICITY;
	
  else if(arena=="Forest")
		return FOREST;
	
  else if(arena=="Sky")
		return SKY;
}


TrainerCenter::~TrainerCenter()
{
  vector<Trainer *>::iterator it;
  for(it=trainerlst.begin(); it!=trainerlst.end(); it++)
      delete (*it);
  trainerlst.clear();
}