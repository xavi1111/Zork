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
		if (inventory.size() < 2) {
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
		else
			cout << "You cannot pick more than 2 items at a time\n";
	}
}

void Player::dropItem(const string& item) 
{
	bool notFound = true;
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
		for (int i = 0; i<inventory.size(); i++)
		{
			if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
			{
				currentRoom->addItemInRoom(inventory[i]);
				removeFromInventory(inventory[i].name);
				cout << "You droped " << item << "\n";
				notFound = false;
			}
		}
		if(notFound)
			cout << "There is no such item in your inventory" << "\n";
	}
}

void Player::sayHello(const string& name)
{
	bool notFound = true;
	if (currentRoom->npcsAvailable.size()>0) 
	{
		for (int i = 0; i < currentRoom->npcsAvailable.size(); i++)
		{
			if (_stricmp(currentRoom->npcsAvailable[i].name.c_str(), name.c_str()) == 0)
			{
				currentRoom->npcsAvailable[i].converstionLoop();
				notFound = false;
			}
		}
		if (notFound)
			cout << "There is no such NPC in this room" << "\n";
	}
	else 
	{
		cout << "There is no one to say hello to\n";
	}
}

void Player::showInventory() 
{
	for (int i = 0; i<inventory.size(); i++) 
		cout << inventory[i].name << "\n";
	if (inventory.size() == 0)
		cout << "You have no items in the inventory" << "\n";

}

void Player::interact()
{
	string password;
	if (currentRoom->hasEndingButton) 
	{
		cout << "Please introduce password : \n";
		cin >> password;
		if (_stricmp(password.c_str(), "2309") == 0)
		{
			for (int i = 0; i < map.roomsInMap.size(); i++)
			{
				if (_stricmp(map.roomsInMap[i].name.c_str(), "Garbage room") == 0)
				{
					bool conditionsRequired = false;
					for (int j = 0; j < map.roomsInMap[i].itemsInRoom.size(); j++)
					{
						if (_stricmp(map.roomsInMap[i].itemsInRoom[j].name.c_str(), "egg") == 0 && map.roomsInMap[i].hasAlien)
						{
							finishedGame = true;
							cout << "You incinerate the alien and the last remaining egg you saved yourself now you can reach home safely.\n";
							conditionsRequired = true;
						}

					}
					if(!conditionsRequired)
						cout << "Either the egg or the alien is not in the Garbage Room.\n";
				}
			}
		}

	}
	else
		cout << "There is nothing to interact with\n";
}

void Player::examineItem(const string& item) 
{
	bool notFound = true;
	for (int i = 0; i<inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
		{
			cout << inventory[i].description << "\n";
			notFound = false;
		}
	}
	if(notFound)
		cout << "There is no such item in your inventory" << "\n";
}

void Player::useItem(const string& item)
{
	bool notFound = true;
	for (int i = 0; i<inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
		{
			notFound = false;
			if (_stricmp("wrench", item.c_str()) == 0) 
			{
				cout << "You look at the wrench, maybe you could open something with it." << "\n";
			}
			else if (_stricmp("lighter", item.c_str()) == 0)
			{
				cout << "You start playing with the lighter but stop fearing of emptying the gas." << "\n";
			}
			else if (_stricmp("cigarettes", item.c_str()) == 0)
			{
				bool lighterFound = false;
				for (int j = 0; j<inventory.size(); j++)
				{
					if (_stricmp(inventory[j].name.c_str(), "lighter") == 0)
					{
						cout << "You light a cigarette and take a moment for yourself." << "\n";
						lighterFound = true;
					}
				}
				if (!lighterFound)
					cout << "You need to have a lighter in your inventory. The backpack is not your inventory." << "\n";
			}
			else if (_stricmp("egg", item.c_str()) == 0)
			{
				cout << "You look at the egg, you can feel a creature inside it, maybe someone could help you figure out what to do with it" << "\n";
			}
			else if (_stricmp("keycard", item.c_str()) == 0)
			{
				cout << "You look at the keycard, maybe you could open something with it" << "\n";
			}
			else if (_stricmp("fireworks", item.c_str()) == 0)
			{
				bool lighterFound = false;
				for (int j = 0; j<inventory.size(); j++)
				{
					if (_stricmp(inventory[j].name.c_str(), "lighter") == 0)
					{
						cout << "You light and throw a firework it makes a loud sound, maybe loud enough to scare the alien." << "\n";
						lighterFound = true;
					}
				}
				if(!lighterFound)
					cout << "You need to have a lighter in your inventory. The backpack is not your inventory." << "\n";
			}
		}
	}
	if (notFound)
		cout << "There is no such item in your inventory" << "\n";
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
	if (inventory.size() < 2) 
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
	else
		cout << "You cannot pick more than 2 items at a time\n";
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