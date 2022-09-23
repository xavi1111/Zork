#pragma once
#ifndef __Room__
#define __Room__
#include <string>
#include <vector>
#include "Item.h"
#include "Backpack.h"
#include "NPC.h"

using namespace std;

class Room
{
public:
	Room(string& name, string& description, vector<string>& possibleDirections, vector<string>& connectionType, vector<string>& roomNames, vector<bool>& entranceLocked, vector<string>& itemNeeded, vector<string>& itemBlocked);
	void getInfo();
	void addItemInRoom(Item& itemToAdd);
	void removeItemInRoom(string& itemName);
	void addNPC(NPC& npcToAdd);
	void removeNPC(string& npcName);
	string name;
	string description;
	vector<Item> itemsInRoom;
	vector<string> possibleDirections;
	vector<string> connectionType;
	vector<string> roomNames;
	vector<bool> entranceLocked;
	vector<string> itemNeeded;
	vector<string> itemBlocked;
	vector<NPC> npcsAvailable;
	bool hasEndingButton = false;
	bool hasAlien = false;
	bool hasBackpack = false;
};
#endif