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
	cout << description;
	for (int i = 0; i < itemsInRoom.size(); i++)
	{
		cout << " " << itemsInRoom[i].roomDescription;
	}
	if (hasBackpack)
		cout << "You can see a backpack that can be useful for carrying more items.";
	cout << "\n";
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

void Room::addNPC(NPC& npcToAdd)
{
	npcsAvailable.push_back(npcToAdd);
}

void Room::removeNPC(string& npcName)
{
	for (int i = 0; i < npcsAvailable.size(); i++)
	{
		if (_stricmp(npcsAvailable[i].name.c_str(), npcName.c_str()) == 0)
		{
			npcsAvailable.erase(npcsAvailable.begin() + i);
		}

	}
}

