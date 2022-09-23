#pragma once
#ifndef __Backpack__
#define __Backpack__
#include <string>
#include <vector>
#include "Item.h"

using namespace std;

class Backpack
{
public:
	Backpack(string& itemName, string& description);
	void addItemToBag(Item& item);
	void removeItemFromBag(string& itemName);
	void getDescription() const;
	vector<Item> itemsInBag;
	string name;
	string description;

public:

};

#endif 
