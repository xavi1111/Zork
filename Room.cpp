#include <iostream>
#include "Room.h"

using namespace std;

Room::Room(string& description)
{
	Room::description = description;
	return;
}

void Room::getInfo()
{
	cout << description<<'\n';
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
