#include <string>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Room.h"
#include "Map.h"
#include "Item.h"
#include "Backpack.h"

using namespace std;

Player::Player() 
{
	Player::currentRoom = &map.roomsInMap[0];
	
}

void Player::move(const string& direction) 
{
	bool changedRoom = false;
	if (canMove(direction)) 
	{
		for (int i = 0; i < currentRoom->possibleDirections.size(); i++)
		{
			if (_stricmp(currentRoom->possibleDirections[i].c_str(), direction.c_str()) == 0)
			{
				for (int j = 0; j < map.roomsInMap.size(); j++)
				{
					if (_stricmp(map.roomsInMap[j].name.c_str(), currentRoom->roomNames[i].c_str()) == 0 && currentRoom->entranceLocked[i] == false)
					{
						cout << "You go through" << currentRoom->connectionType[i] << "\n";
						currentRoom = &map.roomsInMap[j];
						currentRoom->getInfo();
						changedRoom = true;
						break;
					}
					else if (currentRoom->entranceLocked[i] == true)
					{
						cout << "The " << currentRoom->itemBlocked[i] << " is blocked you need the following item: " << currentRoom->itemNeeded[i] << "\n";
						changedRoom = true;
						break;
					}
				}
				if (changedRoom)
					break;
			}
		}
	}
	else
		cout << "You cannot go that way" << "\n";
}

bool Player::canMove(const string& direction) 
{
	for (int i = 0; i < currentRoom->possibleDirections.size(); i++) 
	{
		if (_stricmp(currentRoom->possibleDirections[i].c_str(), direction.c_str()) == 0)
		{
			return true;
		}
	}
	return false;
}

void Player::takeItem(const string& item) 
{
	bool noItemFound = true;
	if (_stricmp("backpack", item.c_str()) == 0)
	{
		if (currentRoom->hasBackpack)
		{
			currentRoom->hasBackpack = false;
			hasBackpack = true;
			cout << "You picked up a backpack\n";
		}
		else
		{
			cout << "There is no such item in this room" << "\n";
		}
	}
	else {
		for (int i = 0; i<currentRoom->itemsInRoom.size(); i++) 
		{
			if (_stricmp(currentRoom->itemsInRoom[i].name.c_str(), item.c_str()) == 0)
			{
				Player::inventory.push_back(currentRoom->itemsInRoom[i]);
				currentRoom->removeItemInRoom(currentRoom->itemsInRoom[i].name);
				cout << "You picked up " << item << "\n";
				noItemFound = false;
			}
		
		}
		if(noItemFound)
			cout << "There is no such item in this room" << "\n";

	}
}

void Player::dropItem(const string& item) 
{
	if (_stricmp("backpack", item.c_str()) == 0)
	{
		if (hasBackpack)
		{
			currentRoom->hasBackpack = true;
			hasBackpack = false;
			cout << "You droped a backapck\n";
		}
		else
		{
			cout << "There is no such item in your inventory" << "\n";
		}
	}
	else {
		for (int i = 0; inventory.size(); i++)
		{
			if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
			{
				currentRoom->addItemInRoom(inventory[i]);
				removeFromInventory(inventory[i].name);
				cout << "You droped " << item << "\n";
			}
			else
				cout << "There is no such item in your inventory" << "\n";
		}
	}
}

void Player::sayHello() 
{

}

void Player::showInventory() 
{
	for (int i = 0; i<inventory.size(); i++) 
		cout << inventory[i].name << "\n";
	if (inventory.size() == 0)
		cout << "You have no items in the inventory" << "\n";

}

void Player::examineItem(const string& item) 
{
	for (int i = 0; inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
		{
			cout << inventory[i].description << "\n";
		}
		else
			cout << "There is no such item in your inventory" << "\n";
	}
}

void Player::putItem(const string& item, const string& place) 
{
	bool noItemFound = true;
	for (int i = 0; i < inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
		{
			if (_stricmp("backpack", place.c_str()) == 0 && hasBackpack)
			{
				backpack->addItemToBag(inventory[i]);
				cout << "You put " << inventory[i].name << " in the backpack\n";
				removeFromInventory(inventory[i].name);
			}	
			else
				cout << "You cannot place an item there\n";
			noItemFound = false;
		}

	}
	if (noItemFound)
		cout << "There is no such item in your Inventory" << "\n";
}

void Player::getFrom(const string& item, const string& place) 
{
	bool noItemFound = true;
	for (int i = 0; i < backpack->itemsInBag.size(); i++)
	{
		if (_stricmp(backpack->itemsInBag[i].name.c_str(), item.c_str()) == 0)
		{
			if (_stricmp("backpack", place.c_str()) == 0 && hasBackpack)
			{
				inventory.push_back(backpack->itemsInBag[i]);
				cout << "You put " << backpack->itemsInBag[i].name << " in your inventory\n";
				backpack->removeItemFromBag(backpack->itemsInBag[i].name);
			}
			else
				cout << "You cannot place an item there\n";
			noItemFound = false;
		}

	}
	if (noItemFound)
		cout << "There is no such item in your Inventory" << "\n";
}

void Player::open(const string& thing, const string& item) 
{
	bool itemFound = false;
	bool blockedItemFound = false;
	for (int i = 0; i < currentRoom->itemBlocked.size(); i++)
	{
		if (_stricmp(currentRoom->itemBlocked[i].c_str(), thing.c_str()) == 0)
		{
			for (int j = 0; j < inventory.size(); j++)
			{
				if (_stricmp(inventory[j].name.c_str(), item.c_str()) == 0 && _stricmp(inventory[j].name.c_str(), currentRoom->itemNeeded[i].c_str()) == 0)
				{
					currentRoom->entranceLocked[i] = false;
					cout << "The " << currentRoom->itemBlocked[i] << " has been unlocked" << "\n";
					itemFound = true;
				}
				else if (_stricmp(inventory[j].name.c_str(), item.c_str()) == 0 && _stricmp(inventory[j].name.c_str(), currentRoom->itemNeeded[i].c_str()) != 0)
				{
					cout << "This is not the needed item to open the "<< currentRoom->itemBlocked[i] << "\n";
					itemFound = true;
				}

			}
			if(!itemFound)
				cout << "There is no such item in your inventory" << "\n";
			blockedItemFound = true;
		}
	}
	if (!blockedItemFound)
		cout << "There is no such thing to unlock in this room" << "\n";
}

void Player::removeFromInventory(const string& itemName) 
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), itemName.c_str()) == 0)
		{
			inventory.erase(inventory.begin() + i);
		}

	}
}