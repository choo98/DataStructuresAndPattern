#pragma once
#include <iostream>
#include <string>

//base class to be used for the builder later on to create different kind of monsters
using namespace std;

class Monster
{
private: 
	string mobName;
	int mobHP, mobDMG;
public:
	// set the monster details
	void setMobName(const string& name);
	void setMobHP(const int HP);
	void setMobDMG(const int DMG);

	// get the monster's HP and DMG
	int getMobHP();
	int getMobDMG();

	void calMobHP(int pDmg);

	// Initialize the monster event
	void mobEvent() const
	{
		cout << "The monster in front of you is " << mobName << endl;
	}
};

