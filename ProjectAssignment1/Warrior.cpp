#include "Warrior.h"
#include "Visitor.h"
#include<iostream>
using namespace std;

Warrior::Warrior()
{
	cName="";
	fHp = 20;
	fStr = 6;
	fAgi = 3;
	fDmg = 5;
}


Warrior::Warrior(string cName)
{
	this->cName = cName;
	this->fHp = 20;
	this->fStr = 6;
	this->fAgi = 3;
	this->fDmg = 5;
}


Warrior::~Warrior()
{
}

void Warrior::accept(Visitor& v)
{
	v.Visit(*this);
}

