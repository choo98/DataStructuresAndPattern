#pragma once
#include "BaseClass.h"
using namespace std;

// Child class of BaseClass
class Warrior: public BaseClass
{
public:
	Warrior();


	Warrior(string cName);

	~Warrior();

	//Must impement for visitor to work
	void accept(Visitor& v);

};

