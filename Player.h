#pragma once
#ifndef __Player__
#define __Player__

#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"
#include "Map.h"
#include "Backpack.h"

using namespace std;

class Player
{
public:

	Player();
	void move(const string& direction);
	bool canMove(const string& direction);
	void dropItem(const string& item);
	void sayHello(const string& name);
	void showInventory();
	void interact();
	void takeItem(const string& item);
	void examineItem(const string& item);
	void useItem(const string& item);
	void putItem(const string& item, const string& place);
	void getFrom(const string& item, const string& place);
	void open(const string& thing, const string& item);
	void removeFromInventory(const string& itemName);
	vector<Item> inventory;
	Room* currentRoom;
	Map map;
	Backpack* backpack = NULL;
	bool hasBackpack = false;
	bool finishedGame = false;

};
#endif
