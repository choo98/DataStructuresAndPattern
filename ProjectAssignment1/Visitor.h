#pragma once
#include <iostream>
#include <string>

using namespace std;
//Forward Declaration
class BaseClass;
class Warrior;
class Archer;

class Visitor
{
public:
	virtual void Visit(BaseClass& B);
	virtual void Visit(Warrior& W);
	virtual void Visit(Archer& A);
};

//Responsible to describe the elements or the class
class VisitorDesc : public Visitor
{
	virtual void Visit(Warrior& W);
	virtual void Visit(Archer& A);
};

