#include "PokeFlying.h"

PokeFlying::PokeFlying(int ID, const std::string& pokemonName): Pokemon(ID,pokemonName)
{
	HP=650;
	ATK=55;
	MAG_DEF=0;
	PHY_DEF=15;

	burning=false;
	drowning=false;
	electrified=false;
	rooted=false;

	//Default values
	defHP=650;
	defATK=55;
	defMAG_DEF=0;
	defPHY_DEF=15;
}

void PokeFlying::getDamage()//MAG-Attack (Attacked Pokemon)
{
	//No damage from MAG-Attack
	;
}

void PokeFlying::attackTo(Pokemon* target, Arena currentArena)//PHY-Attack (Attacking Pokemon)
{
	int phyDam=max(1,ATK-target->getPHY_DEF());
	string arena=getArenaName(currentArena);
	
	/*No MAG-Attack*/

	if(arena=="Sky")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(+)"<<endl;
	else if(arena=="Ocean" || arena=="ElectriCity")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(-)"<<endl;
	else
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(/)"<<endl;

	target->setHP(target->getHP()-phyDam);
}



void PokeFlying::levelUp()
{
	HP+=65;
	ATK+=5;
	//MAG_DEF+=0;
	PHY_DEF+=3;

	defHP+=65;
	defATK+=5;
	//defMAG_DEF+=0;
	defPHY_DEF+=3;
}

void PokeFlying::buff(string arena)
{
	if(arena=="Sky")
		(*this)++;
	else if(arena=="Ocean" || arena=="ElectriCity")
		(*this)--;
	else
		;
}

PokeFlying::~PokeFlying()
{}

void PokeFlying::setBurning(bool burning)
{}

void PokeFlying::setDrowning(bool drowning)
{}

void PokeFlying::setElectrified(bool electrified)
{}

void PokeFlying::setRooted(bool rooted)
{}