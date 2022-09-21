#include <string>
#include <iostream>
#include "Item.h"
using namespace std;

Item::Item(string& name, string& description)
{
	Item::name = name;
	Item::description = description;
}

void Item::getDescription() const
{
	cout << Item::description;
}
