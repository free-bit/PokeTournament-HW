#include "PokeGrass.h"

PokeGrass::PokeGrass(int ID, const std::string& pokemonName): Pokemon(ID,pokemonName)
{
	HP=800;
	ATK=40;
	MAG_DEF=0;
	PHY_DEF=30;

	rooted=false;
	burning=false;
	drowning=false;
	electrified=false;

	//Default values
	defHP=800;
	defATK=40;
	defMAG_DEF=0;
	defPHY_DEF=30;
}

void PokeGrass::getDamage()//MAG-Attack (Attacked Pokemon)
{

	if(isBurning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(BURNING)<<"!!!!"<<endl;
		setHP(getHP()-max(0,BURN_DAMAGE*2-getMAG_DEF()));
	}
	if(isDrowning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(DROWNING)<<"!!"<<endl;
		setHP(getHP()-max(0,DROWN_DAMAGE-getMAG_DEF()));
	}
	if(isElectrified() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ELECTRIFIED)<<"!!"<<endl;
		setHP(getHP()-max(0,ELECTRIFY_DAMAGE-getMAG_DEF()));
	}
}

void PokeGrass::attackTo(Pokemon* target, Arena currentArena)//PHY-Attack (Attacking Pokemon)
{
	int phyDam=max(1,ATK-target->getPHY_DEF());
	string arena=getArenaName(currentArena);

	target->setRooted(true);

	if(arena=="Forest")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(+)"<<endl;
	else if(arena=="Magma" || arena=="Sky")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(-)"<<endl;
	else
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(/)"<<endl;

	target->setHP(target->getHP()-phyDam);
}

void PokeGrass::levelUp()
{
	HP+=80;
	ATK+=4;
	//defMAG_DEF+=0;
	PHY_DEF+=3;

	defHP+=80;
	defATK+=4;
	//defMAG_DEF+=0;
	defPHY_DEF+=3;
}

void PokeGrass::buff(string arena)
{
	if(arena=="Forest")
		(*this)++;
	else if(arena=="Magma" || arena=="Sky")
		(*this)--;
	else
		;
}

PokeGrass::~PokeGrass()
{}

void PokeGrass::setBurning(bool burning)
{
	//setOrder("burning");
	this->burning=burning;
}

void PokeGrass::setDrowning(bool drowning)
{
	//setOrder("drowning");
	this->drowning=drowning;
}

void PokeGrass::setElectrified(bool electrified)
{
	//setOrder("electrified");
	this->electrified=electrified;
}

void PokeGrass::setRooted(bool rooted)
{}