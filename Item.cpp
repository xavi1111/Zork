#include <string>
#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(string& name, string& description, string& roomDescription)
{
	Item::name = name;
	Item::description = description;
	Item::roomDescription = roomDescription;
}

void Item::getDescription() const
{
	cout << Item::description;
}
