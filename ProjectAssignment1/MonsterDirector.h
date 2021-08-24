#pragma once
#include "MonsterBuilder.h"

//director class for monster to implement the functions needed

class MonsterDirector 
{
private:
	MonsterBuilder* mobBuilder;

public:
	void createNewMonster(MonsterBuilder* mobBuilder)
	{
		this->mobBuilder = mobBuilder;
		this->mobBuilder->monsterCreation();
		this->mobBuilder->buildMobName();
		this->mobBuilder->buildMobHP();
		this->mobBuilder->buildMobDMG();
	}

	void calDMGTaken(int pDMG)
	{
		// Retrieve the calMobHP function and minus it with player damage
		mobBuilder->getMonster()->calMobHP(pDMG);

	}

	int calMobDMG()
	{
		int mobDMG = mobBuilder->getMonster()->getMobDMG();
		return mobDMG;
	}

	int calMobHP()
	{
		int mobHP = mobBuilder->getMonster()->getMobHP();
		return mobHP;
	}

	void printMobEvent() 
	{
		mobBuilder->getMonster()->mobEvent();
	}

};
