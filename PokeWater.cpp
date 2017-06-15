#include "PokeWater.h"

PokeWater::PokeWater(int ID, const std::string& pokemonName): Pokemon(ID,pokemonName)
{
	HP=700;
	ATK=50;
	MAG_DEF=10;
	PHY_DEF=20;

	drowning=false;
	burning=false;
	electrified=false;
	rooted=false;

	//Default values
	defHP=700;
	defATK=50;
	defMAG_DEF=10;
	defPHY_DEF=20;
}

void PokeWater::getDamage()//MAG-Attack (Attacked Pokemon)
{

	if(isBurning() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(BURNING)<<"!!"<<endl;
		setHP(getHP()-max(0,BURN_DAMAGE-getMAG_DEF()));
	}
	if(isElectrified() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ELECTRIFIED)<<"!!!!"<<endl;
		setHP(getHP()-max(0,ELECTRIFY_DAMAGE*2-getMAG_DEF()));
	}
	if(isRooted() && HP>0)
	{
		cout<<"\t\t\t"<<name<<"("<<HP<<") "<<getEffectName(ROOTED)<<"!!"<<endl;
		setHP(getHP()-max(0,ROOT_DAMAGE-getMAG_DEF()));
	}	
	
}

void PokeWater::attackTo(Pokemon* target, Arena currentArena)//PHY-Attack (Attacking Pokemon)
{
	int phyDam=max(1,ATK-target->getPHY_DEF());
	string arena=getArenaName(currentArena);

	target->setDrowning(true);
	
	if(arena=="Ocean")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(+)"<<endl;
	else if(arena=="ElectriCity" || arena=="Forest")
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(-)"<<endl;
	else
		cout<<"\t\t\t"<<name<<"("<<HP<<") hit "<<target->getName()<<"("<<target->getHP()<<") "<<phyDam<<"(/)"<<endl;

	target->setHP(target->getHP()-phyDam);
}

void PokeWater::levelUp()
{
	HP+=70;
	ATK+=5;
	MAG_DEF+=1;
	PHY_DEF+=2;

	defHP+=70;
	defATK+=5;
	defMAG_DEF+=1;
	defPHY_DEF+=2;
}

void PokeWater::buff(string arena)
{
	if(arena=="Ocean")
		(*this)++;
	else if(arena=="ElectriCity" || arena=="Forest")
		(*this)--;
	else
		;
}

PokeWater::~PokeWater()
{}

void PokeWater::setBurning(bool burning)
{
	this->burning=burning;
}

void PokeWater::setDrowning(bool drowning)
{}

void PokeWater::setElectrified(bool electrified)
{
	this->electrified=electrified;
}

void PokeWater::setRooted(bool rooted)
{
	this->rooted=rooted;
}