#pragma once
#ifndef __Player__
#define __Player__

#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"

using namespace std;

class Player
{
public:

	Player(Room* currentRoom);
	void move(const string& direction);
	bool canMove(const string& direction);
	void dropItem(const string& item);
	void sayHello();
	void showInventory();
	void takeItem(const string& item);
	void examineItem(const string& item);
	void enter(const string& place);
	void putItem(const string& item, const string& place);
	void getFrom(const string& item, const string& place);
	void open(const string& thing, const string& item);
	void attack(const string& enemy, const string& weapon);
	void removeFromInventory(const string& itemName);
	vector<Item> inventory;
	Room* currentRoom;

};
#endif
