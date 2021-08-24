#pragma once
#include "Map.h"


class CurrentTile:public Map
{
private:
	Tiles* head;
public:
	CurrentTile();

	Tiles* current = 0;
};

