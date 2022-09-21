#include <string>
#include <iostream>
#include "Player.h"
#include "Room.h"

using namespace std;

Player::Player(Room* currentRoom) 
{
	Player::currentRoom = currentRoom;
}

void Player::move(const string& direction) {

}

bool Player::canMove(const string& direction) {
	return false;
}

void Player::takeItem(const string& item) {
	bool noItemFound = true;
	for (int i = 0; i<currentRoom->itemsInRoom.size(); i++) 
	{
		if (_stricmp(currentRoom->itemsInRoom[i].name.c_str(), item.c_str()) == 0)
		{
			Player::inventory.push_back(currentRoom->itemsInRoom[i]);
			currentRoom->removeItemInRoom(currentRoom->itemsInRoom[i].name);
			cout << "You picked up " << item << '\n';
			noItemFound = false;
		}
		
	}
	if(noItemFound)
		cout << "There is no such item in this room" << '\n';
}

void Player::dropItem(const string& item) {
	for (int i = 0; inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), item.c_str()) == 0)
		{
			currentRoom->addItemInRoom(inventory[i]);
			removeFromInventory(inventory[i].name);
			cout << "You droped " << item << '\n';
		}
		else
			cout << "There is no such item in this room" << '\n';
	}
}

void Player::sayHello() {

}

void Player::showInventory() {
	for (int i = 0; i<inventory.size(); i++) 
		cout << inventory[i].name << '\n';
	if (inventory.size() == 0)
		cout << "You have no items in the inventory" << '\n';

}

void Player::examineItem(const string& item) {

}

void Player::enter(const string& place) {

}

void Player::putItem(const string& item, const string& place) {

}

void Player::getFrom(const string& item, const string& place) {

}

void Player::open(const string& thing, const string& item) {

}

void Player::attack(const string& enemy, const string& weapon) {

}

void Player::removeFromInventory(const string& itemName) {
	for (int i = 0; i < inventory.size(); i++)
	{
		if (_stricmp(inventory[i].name.c_str(), itemName.c_str()) == 0)
		{
			inventory.erase(inventory.begin() + i);
		}

	}
}