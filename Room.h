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
	Room(string& name, string& description, vector<string>& possibleDirections, vector<string>& connectionType, vector<string>& roomNames);
	void getInfo();
	void addItemInRoom(Item& itemToAdd);
	void removeItemInRoom(string& itemName);
	string name;
	string description;
	vector<Item> itemsInRoom;
	vector<string> possibleDirections;
	vector<string> connectionType;
	vector<string> roomNames;
};
#endif