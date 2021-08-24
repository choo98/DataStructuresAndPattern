#include "Map.h"

Map::Map() 
{
	//I learned how to use singly linked list for creating tiles for events and choices
	//All of this is taught by my friend Lim Jia Lok. (I am just citing this so that i do not get any plagiarism)
	//starting location || testing this out
	string e1 = "You find yourself in a dark cell, You notice that there is a lock on the door, do you use an item from your inventory to unlock it or stay still and give up?";
	string c1 = "\nType Show to show inventory or Type Quit to give up";

	//Tile 2 event and choices
	string e2 = "You walk until you reach an open area and you see a tall and creepy figure, What do you do?";
	string c2 = "Type Show to show inventory or Type Quit to give up\nor Type Move: To Run away or Confront: to face the figure";

	//Tile 3 event and choices
	string e3 = "As you walk futher, you have reached a big door but it is locked with a riddle. On top of the big door it says 'The Lich King' maybe this might be a clue?";
	string c3 = "Type Riddle to solve the puzzle";

	//Tiles 4 Event and choices
	string e4 = "You reach a throne room";
	string c4 = "Type Search to search the throne room or Move to move on to the next location";

	//Tile 5 Event and choices
	string e5 = "As you travel further into the throne room, you notice light coming out from a small doorway and immediately you know that is the exit.\nJust as you were about to make your escape, The owner of this throne room blocks your path.\nAs you feel your legs tremble before him, You think of what you can do to get out of this dire situation, make a run for it? use an item from the backpack or confront the old king.";
	string c5 = "Type Show to show inventory, or type King to attack the King";

	string e6 = "You Defeated the Lich King and nothing is standing in your way to freedom";
	string c6 = "Type Quit to exit the game";


	Tiles* t1 = new Tiles(e1, c1);
	Tiles* t2 = new Tiles(e2, c2);
	Tiles* t3 = new Tiles(e3, c3);
	Tiles* t4 = new Tiles(e4, c4);
	Tiles* t5 = new Tiles(e5, c5);
	Tiles* t6 = new Tiles(e6, c6);

	Start = t1;

	// Pointing nodes to next tiles
	t1->Forward = t2;
	t2->Forward = t3;
	t3->Forward = t4;
	t4->Forward = t5;
	t5->Forward = t6;
}

Map::~Map()
{
}
