#pragma once
#pragma once
#ifndef __Item__
#define __Item__
#include <string>
using namespace std;

class Item
{
public:
	Item(string& name, string& description);
	void getDescription() const;
	string name;
	string description;
};
#endif
