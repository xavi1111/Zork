#pragma once
#ifndef __TextParser__
#define __TextParser__
#include <string>
#include <vector>
#include "Player.h"
#include "Room.h"
using namespace std;

class TextParser 
{
public:
	TextParser();
	vector<string> ParseText(const string& input);
	void checkAction(const vector<string>& action, Player& player, Room& room);
};

#endif