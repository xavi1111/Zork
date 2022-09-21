#pragma once
#ifndef __Player__
#define __Player__

#include <string>
using namespace std;

class Player
{
public:

	Player();
	void move(const string& direction);
	bool canMove(const string& direction);
	void dropItem(const string& item);
	void sayHello();
	void showInventory();
	void takeItem(const string& item);
	void examineItem(const string& item);
	void enter(const string& place);
	void putItem(const string& item, const string& place);
	void getFrom(const string& item, const string& place);
	void open(const string& thing, const string& item);
	void attack(const string& enemy, const string& weapon);

};
#endif
