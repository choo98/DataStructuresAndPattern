#pragma once
#include "MonsterBuilder.h"
class KingBuilder : public MonsterBuilder
{
public:

	void buildMobName() const override
	{
		monster->setMobName("The Lich King");
	}

	void buildMobHP() const override
	{
		monster->setMobHP(20);
	}

	void buildMobDMG() const override
	{
		monster->setMobDMG(5);
	}


};