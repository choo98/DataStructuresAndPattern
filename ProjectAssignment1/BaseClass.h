#pragma once
#include <iostream>
#include "Map.h"

using namespace std;

//Forward Declaration
class Visitor;

class BaseClass
{
protected:
	string cName;
	int fHp;
	int fStr; // affects HP
	int fAgi; // affects DMG
	int fDmg;



public:
	BaseClass(); // default constructor

	BaseClass(string cName);// overloaded constructor

	//getter and setter for variables
	string getcName();
	void setcName(string cName);

	int getHp();
	void setHp(int Hp);

	int getStr();
	void setStr(int fStr);

	int getAgi();
	void setAgi(int fAgi);

	int getDmg();
	void setDmg(int fDmg);

	void pReceiveDMG(int mDMG);

	void plusHP(int hpValue);

	void plusDMG(int DMGValue);

	void printStatus();

	//friend insertion operator overloader
	friend istream& operator >>(istream& istream, BaseClass& baseclass);

	//Must implement this for visitor to work
	virtual void accept(Visitor& v);

	~BaseClass();//destructor


};

