#pragma once
#ifndef __Room__
#define __Room__
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Room
{
public:
	Room(string& description);
	void getInfo();
	void addItemInRoom(Item& itemToAdd);
	void removeItemInRoom(string& itemName);
	string description;
	vector<Item> itemsInRoom;
};
#endif