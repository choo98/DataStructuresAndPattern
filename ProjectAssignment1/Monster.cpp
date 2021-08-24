#include "Monster.h"

void Monster::setMobName(const string& name)
{
	this->mobName = name;
}

void Monster::setMobHP(const int HP)
{
	this->mobHP = HP;
}

void Monster::setMobDMG(const int DMG)
{
	this->mobDMG = DMG;
}

int Monster::getMobHP()
{
	return mobHP;
}

int Monster::getMobDMG()
{
	return mobDMG;
}

void Monster::calMobHP(int pDmg)
{
	mobHP -= pDmg;
}
