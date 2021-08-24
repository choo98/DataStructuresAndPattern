#pragma once
#include <string>

using namespace std;

class Tiles
{
private:
	string fChoice;
	string fEvent;
public:
	Tiles();
	Tiles(string fEvent,string fChoice);

	Tiles* Forward;

	Tiles* Next;

	void printEvent();
	void printChoices();

	~Tiles();
};

