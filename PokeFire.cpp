#include "PokeFire.h"

PokeFire::PokeFire(int ID, const std::string& pokemonName): Pokemon(ID,pokemonName)
{
	HP=600;
	ATK=60;
	MAG_DEF=20;
	PHY_DEF=10;

	burning=false;
	electrified=false;
	drowning=false;
	rooted=false;

	//Default values
	defHP=600;
	defATK=60;
	defMAG_DEF=20;
	defPHY_DEF=10;
}

void PokeFire::getDamage()//MAG-Attack (Attacked Pokemon)
{
	if(isDrowning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(DROWNING)<<"!!!!"<<endl;
		setHP(getHP()-max(0,DROWN_DAMAGE*2-getMAG_DEF()));
	}
	if(isElectrified() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ELECTRIFIED)<<"!!"<<endl;
		setHP(getHP()-max(0,ELECTRIFY_DAMAGE-getMAG_DEF()));
	}
	if(isRooted() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ROOTED)<<"!!"<<endl;
		setHP(getHP()-max(0,ROOT_DAMAGE-getMAG_DEF()));
	}
}



void PokeFire::attackTo(Pokemon* target, Arena currentArena)//PHY-Attack (Attacking Pokemon)
{
	int phyDam=max(1,ATK-target->getPHY_DEF());
	string arena=getArenaName(currentArena);

	target->setBurning(true);

	if(arena=="Magma")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(+)"<<endl;
	else if(arena=="Ocean" || arena=="Sky")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(-)"<<endl;
	else
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(/)"<<endl;
		
	target->setHP(target->getHP()-phyDam);
}

void PokeFire::levelUp()
{
	HP+=60;
	ATK+=6;
	MAG_DEF+=2;
	PHY_DEF+=1;

	defHP+=60;
	defATK+=6;
	defMAG_DEF+=2;
	defPHY_DEF+=1;
}

void PokeFire::buff(string arena)
{
	if(arena=="Magma")
		(*this)++;
	else if(arena=="Ocean" || arena=="Sky")
		(*this)--;
	else
		;
}

PokeFire::~PokeFire()
{}

void PokeFire::setBurning(bool burning)
{}

void PokeFire::setDrowning(bool drowning)
{
	this->drowning=drowning;
}

void PokeFire::setElectrified(bool electrified)
{
	this->electrified=electrified;
}

void PokeFire::setRooted(bool rooted)
{
	this->rooted=rooted;
}