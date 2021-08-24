#pragma once
#include "MonsterBuilder.h"
class OrcBuilder : public MonsterBuilder
{
public:

	void buildMobName() const override 
	{
		monster->setMobName("Dark Orc");
	}

	void buildMobHP() const override
	{
		monster->setMobHP(10);
	}

	void buildMobDMG() const override
	{
		monster->setMobDMG(5);
	}


};