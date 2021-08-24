#include "Tiles.h"
#include <iostream>

using namespace std;

Tiles::Tiles()
{
	//does nothing
}

Tiles::Tiles(string fEvent,string fChoice)
{
	this->fEvent = fEvent;
	this->fChoice = fChoice;
}

void Tiles::printEvent()
{
	cout << fEvent << endl;
}

void Tiles::printChoices()
{
	cout << fChoice << endl;
}

Tiles::~Tiles()
{
	//destructor
}
