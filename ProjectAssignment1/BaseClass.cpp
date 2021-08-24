#include "BaseClass.h"
#include "Visitor.h"
#include <iostream>

using namespace std;

BaseClass::BaseClass()
{
	cName = "";
	fHp = 10;
	fStr = 1;
	fAgi = 1;
	fDmg = 5;
}

BaseClass::BaseClass(string cName)
{
	this->cName = cName;
	this->fHp = 10;
	this->fStr = 1;
	this->fAgi = 1;
	this->fDmg = 5;
}


string BaseClass::getcName()
{
	return cName;
}

void BaseClass::setcName(string cName)
{
	this->cName = cName;
}

int BaseClass::getHp()
{
	return this->fHp;
}

void BaseClass::setHp(int Hp)
{
	this->fHp = fHp;
}

int BaseClass::getStr()
{
	return this->fStr;
}

void BaseClass::setStr(int fStr)
{
	this->fStr = fStr;
}

int BaseClass::getAgi()
{
	return this->fAgi;
}

void BaseClass::setAgi(int fAgi)
{
	this->fAgi = fAgi;
}

int BaseClass::getDmg()
{
	return this->fDmg;
}

void BaseClass::setDmg(int fDmg)
{
	this->fDmg = fDmg;
}

void BaseClass::pReceiveDMG(int mDMG)
{
	fHp -= mDMG;
}

void BaseClass::plusHP(int hpValue)
{
	fHp += hpValue;
}

void BaseClass::plusDMG(int DMGValue)
{
	fDmg += DMGValue;
}


void BaseClass::printStatus()
{
	cout << "Your current stats: " << endl;
	cout << "Name: " << cName << " HP: " << fHp << " STR: " << fStr << " AGI: " << fAgi << " Damage: " << fDmg <<endl;
}


void BaseClass::accept(Visitor& v)
{
	v.Visit(*this);
}

BaseClass::~BaseClass()
{
}

istream& operator>>(istream& istream, BaseClass& baseclass)
{
	string commandLine;
	int tempValue;


	istream >> commandLine >> tempValue;
	if (commandLine == "Damage") {
		baseclass.fDmg += tempValue;
	}
	if (commandLine == "HP")
	{
		baseclass.fHp += tempValue;
	}
	return istream;
}
