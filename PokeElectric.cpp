#include "PokeElectric.h"

PokeElectric::PokeElectric(int ID, const std::string& pokemonName): Pokemon(ID,pokemonName)
{
	HP=500;
	ATK=70;
	MAG_DEF=30;
	PHY_DEF=0;

	electrified=false;
	burning=false;
	drowning=false;
	rooted=false;

	//Default values
	defHP=500;
	defATK=70;
	defMAG_DEF=30;
	defPHY_DEF=0;
}

void PokeElectric::getDamage()//MAG-Attack (Attacked Pokemon)
{
	if(isBurning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(BURNING)<<"!!"<<endl;
		setHP(getHP()-max(0,BURN_DAMAGE-getMAG_DEF()));
	}
	if(isDrowning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(DROWNING)<<"!!"<<endl;
		setHP(getHP()-max(0,DROWN_DAMAGE-getMAG_DEF()));
	}
	if(isRooted() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ROOTED)<<"!!!!"<<endl;
		setHP(getHP()-max(0,ROOT_DAMAGE*2-getMAG_DEF()));
	}
}


void PokeElectric::attackTo(Pokemon* target, Arena currentArena)//PHY-Attack (Attacking Pokemon)
{
	int phyDam=max(1,ATK-target->getPHY_DEF());
	string arena=getArenaName(currentArena);

	target->setElectrified(true);

	if(arena=="ElectriCity")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(+)"<<endl;
	else if(arena=="Magma" || arena=="Forest")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(-)"<<endl;
	else
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(/)"<<endl;

	target->setHP(target->getHP()-phyDam);
}

void PokeElectric::levelUp()
{
	HP+=50;
	ATK+=7;
	MAG_DEF+=3;

	defHP+=50;
	defATK+=7;
	defMAG_DEF+=3;
	//PHY_DEF+=0;
}

void PokeElectric::buff(string arena)
{
	if(arena=="ElectriCity")
		(*this)++;
	else if(arena=="Magma" || arena=="Forest")
		(*this)--;
	else
		;
}

PokeElectric::~PokeElectric()
{}

void PokeElectric::setBurning(bool burning)
{
	this->burning=burning;
}

void PokeElectric::setDrowning(bool drowning)
{
	this->drowning=drowning;
}

void PokeElectric::setElectrified(bool electrified)
{}

void PokeElectric::setRooted(bool rooted)
{
	this->rooted=rooted;
}