#pragma once
#include "BaseClass.h"
using namespace std;


class Archer: public BaseClass
{
public:
	Archer();

	Archer(string cName);

	~Archer();

	//Must impement for visitor to work
	void accept(Visitor& v);
};

