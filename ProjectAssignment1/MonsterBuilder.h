#pragma once
#include "Monster.h"

//Builder class

// Sources used for builder pattern
// https://cppcodetips.wordpress.com/tag/builder-design-pattern-explained-with-c-samples/

class MonsterBuilder 
{
protected:
	Monster* monster; // so that can be accessed in sub monster classes later on

public:

	//create monster
	void monsterCreation()
	{
		monster = new Monster();
	}

	//get monster
	Monster* getMonster()
	{
		return monster;
	}

	virtual void buildMobName() const = 0;
	virtual void buildMobHP() const = 0;
	virtual void buildMobDMG() const = 0;

	//destructor
	virtual ~MonsterBuilder() {}
};
