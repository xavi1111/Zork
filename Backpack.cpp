#include <string>
#include <vector>
#include <iostream>
#include "Backpack.h"
#include "Item.h"

using namespace std;

Backpack::Backpack(string& Name, string& description)
{
	Backpack::name = name;
	Backpack::description = description;
}

void Backpack::addItemToBag(Item& item)
{
	itemsInBag.push_back(item);
}

void Backpack::removeItemFromBag(string& itemName)
{
	for (int i = 0; i < itemsInBag.size(); i++)
	{
		if (_stricmp(itemsInBag[i].name.c_str(), itemName.c_str()) == 0)
		{
			itemsInBag.erase(itemsInBag.begin() + i);
		}

	}
}

void Backpack::getDescription() const
{
	cout << Backpack::description <<"\n";
	for (int i = 0; i < itemsInBag.size(); i++)
	{
		cout << itemsInBag[i].name << "\n";

	}
}
