#include "Archer.h"
#include "Visitor.h"

Archer::Archer()
{
	cName = "";
	fHp = 15;
	fStr = 3;
	fAgi = 6;
	fDmg = 5;
}

Archer::Archer(string cName)
{
	this->cName = cName;
	this->fHp = 15;
	this->fStr = 3;
	this->fAgi = 6;
	this->fDmg = 7;
}

Archer::~Archer()
{
}

void Archer::accept(Visitor& v)
{
	v.Visit(*this);
}
