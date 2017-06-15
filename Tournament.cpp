#include "Tournament.h"

Tournament::Tournament(const std::string& tName):
tournamentName(tName),lst(vector<Trainer*>())
{}

Tournament::~Tournament()
{
	lst.clear();
}

void Tournament::registerTrainers(const std::vector<Trainer*>& trainers)
{
	lst=trainers;//Shallow copy
}

Trainer* Tournament::commence()
{
	int winner,i,j;
	Trainer *trainer1=NULL,*trainer2=NULL;
	vector<Trainer*> nextRound;
	while(getSize()!=1)
	{
		//Initialize
		i=0;
		j=getSize()-1;
		while(i<j)
		{
			winner=0;//Default
			cout<<"Started Round: "<<i<<" vs "<<j<<endl;
			trainer1=getFront();
			trainer2=getBack();
		
			trainer1->restoreAllPokemons();
			trainer2->restoreAllPokemons();
			winner+=duelBetween(trainer1,trainer2,trainer1->getFavoriteArena());

			winner-=duelBetween(trainer2,trainer1,trainer2->getFavoriteArena());//Reverted due to argument order

			winner+=duelBetween(trainer1,trainer2,STADIUM);

			//if winner +, trainer1 wins
			//if winner -, trainer2 wins
			Trainer *winnerT, *loserT;
			if(winner>0)
			{
				cout<<"Round Winner: "<<trainer1->getName()<<"!"<<endl;
				i++;
				j--;
				winnerT=trainer1;
				winnerT->restoreAllPokemons();
				nextRound.push_back(winnerT);

				loserT=trainer2;
				
				removeFront();
				removeBack();
			}
			else
			{
				cout<<"Round Winner: "<<trainer2->getName()<<"!"<<endl;
				i++;
				j--;

				winnerT=trainer2;
				winnerT->restoreAllPokemons();
				nextRound.push_back(winnerT);

				loserT=trainer1;

				removeFront();
				removeBack();
			}		
		}
		lst=nextRound;
		nextRound.clear();
	}
	return getFront();//Ultimate winner
}

int Tournament::duelBetween(Trainer* trainer1, Trainer* trainer2, Arena currentArena)
{
	//No removal from the list
	string arena=getArenaName(currentArena);
	Pokemon *pokemon1=NULL, *pokemon2=NULL;
	int i=0,j=0,winner=-1;//trainer1 will start attacking

	cout<<"\t"<<trainer1->getName()<<" vs "<<trainer2->getName()<<": "<<arena<<endl;
	
	while(i<trainer1->getSize() && j<trainer2->getSize())//Out of bounds indicates no pokemon left
	{
		//Summon pokemons if there is not already any
		if(!pokemon1)
		{
			pokemon1=trainer1->getPokemonAt(i);
			pokemon1->buff(arena);
		}
		if(!pokemon2)
		{
			pokemon2=trainer2->getPokemonAt(j);
			pokemon2->buff(arena);
		}
		
		//Loser of last turn starts attacking
		if(winner==-1)
		{
			winner=duelBetween(pokemon1,pokemon2,currentArena);
		}
		else
		{
			winner=-duelBetween(pokemon2,pokemon1,currentArena);//reverted
		}

		if(winner==1)//T1's pokemon wins
		{
			pokemon2=NULL;//pokemon dies
			j++;//next pokemon
		}
		else		 //T2's pokemon wins
		{
			pokemon1=NULL;//pokemon dies
			i++;//next pokemon
		}
	}
	if(i<trainer1->getSize()) 		//Trainer1 wins
	{
		cout<<"\t"<<"WinnerT:"<<trainer1->getName()<<"\n\n";
		//Reset pokemons for the next round.
		trainer1->restoreAllPokemons();
		trainer2->restoreAllPokemons();
		return 1;
	}
	else if(j<trainer2->getSize())	//Trainer2 wins
	{
		cout<<"\t"<<"WinnerT:"<<trainer2->getName()<<"\n\n";
		//Reset pokemons for the next round.
		trainer1->restoreAllPokemons();
		trainer2->restoreAllPokemons();
		return -1;
	}
}

const std::string& Tournament::getTournamentName() const
{
	return tournamentName;
}

int Tournament::duelBetween(Pokemon *pokemon1, Pokemon *pokemon2, Arena currentArena)
{ 
	string arena=getArenaName(currentArena);

	while(pokemon1->getHP()>0 && pokemon2->getHP()>0)
	{
		if(pokemon1->getHP()>0)
		{
			pokemon1->getDamage();
		}
		else
		{
			cout<<"\t\t"<<"WinnerP:"<<pokemon2->getName()<<endl;
			pokemon2->levelUp();
			return -1;//Indicates victory of 2nd
		}
		if(pokemon1->getHP()>0)
		{
			pokemon1->attackTo(pokemon2,currentArena);
		}
		else
		{
			cout<<"\t\t"<<"WinnerP:"<<pokemon2->getName()<<endl;
			pokemon2->levelUp();
			return -1;//Indicates victory of 2nd
		}
		if(pokemon2->getHP()>0)
		{
			pokemon2->getDamage();
		}
		else
		{
			cout<<"\t\t"<<"WinnerP:"<<pokemon1->getName()<<endl;
			pokemon1->levelUp();
			return 1;//Indicates victory of 1st
		}
		if(pokemon2->getHP()>0)
		{
			pokemon2->attackTo(pokemon1,currentArena);
		}
		else
		{
			cout<<"\t\t"<<"WinnerP:"<<pokemon1->getName()<<endl;
			pokemon1->levelUp();
			return 1;//Indicates victory of 1st
		}
	}
	if(pokemon1->getHP()>0)        //Pokemon1 wins
	{
		cout<<"\t\t"<<"WinnerP:"<<pokemon1->getName()<<endl;
		pokemon1->levelUp();
		return 1;//Indicates victory of 1st
	}
	else if(pokemon2->getHP()>0)   //Pokemon2 wins
	{
		cout<<"\t\t"<<"WinnerP:"<<pokemon2->getName()<<endl;
		pokemon2->levelUp();
		return -1;//Indicates victory of 2nd
	}
}

int Tournament::getSize()
{
	return lst.size();
}

Trainer* Tournament::getFront()
{
	return lst.front();
}

Trainer* Tournament::getBack()
{
	return lst.back();
}

void Tournament::removeFront()
{
	lst.erase(lst.begin());
}

void Tournament::removeBack()
{
	lst.pop_back();
}