#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(string& name, string& description, vector<string>& possibleDirections, vector<string>& connectionType, vector<string>& roomNames, vector<bool>& entranceLocked, vector<string>& itemNeeded, vector<string>& itemBlocked)
{
	Room::name = name;
	Room::description = description;
	Room::possibleDirections = possibleDirections;
	Room::connectionType = connectionType;
	Room::roomNames = roomNames;
	Room::entranceLocked = entranceLocked;
	Room::itemNeeded = itemNeeded;
	Room::itemBlocked = itemBlocked;
}

void Room::getInfo()
{
	cout << description << "\n";
}

void Room::addItemInRoom(Item& itemToAdd)
{
	itemsInRoom.push_back(itemToAdd);
}

void Room::removeItemInRoom(string& itemName)
{
	for (int i = 0; i < itemsInRoom.size(); i++) 
	{
		if (_stricmp(itemsInRoom[i].name.c_str(), itemName.c_str()) == 0) 
		{
			itemsInRoom.erase(itemsInRoom.begin() + i);
		}
			
	}
}

