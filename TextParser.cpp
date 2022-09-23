#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "TextParser.h"
#include "Player.h"
#include "Room.h"

using namespace std;

TextParser::TextParser() 
{
	return ;
}

vector<string> TextParser::ParseText(const string& input) 
{
	vector<string> tokens;
	stringstream stream(input);
	string currentWord;

	while (getline(stream, currentWord, ' '))
	{
		tokens.push_back(currentWord);
	}
	return tokens;
}

void TextParser::checkAction(const vector<string>& action, Player& player)
{
	bool error = true;
	if (action.size() == 1)
	{
		error = false;
		if (_stricmp(action[0].c_str(), "north") == 0) 
		{
			player.move(action[0]);
		}
		else if (_stricmp(action[0].c_str(), "south") == 0)
		{
			player.move(action[0]);
		}
		else if (_stricmp(action[0].c_str(), "east") == 0)
		{
			player.move(action[0]);
		}
		else if (_stricmp(action[0].c_str(), "west") == 0)
		{
			player.move(action[0]);
		}
		else if (_stricmp(action[0].c_str(), "look") == 0)
		{
			player.currentRoom->getInfo();
		}
		else if (_stricmp(action[0].c_str(), "inventory") == 0)
		{
			player.showInventory();
		}
		else if (_stricmp(action[0].c_str(), "interact") == 0)
		{
			player.interact();
		}
		else if (_stricmp(action[0].c_str(), "commands") == 0)
		{
			cout << "The posible commands are: north / south / east / west / look / enter / hello / inventory / commands / exit / take X / move X / examine X / drop X / put X Y / get X Y / open X Y / attack X Y \n";
		}
		else
			error = true;
	}
	else if (action.size() == 2)
	{
		error = false;
		if (_stricmp(action[0].c_str(), "take") == 0) 
		{
			player.takeItem(action[1]);
		}
		else if (_stricmp(action[0].c_str(), "move") == 0)
		{
			player.move(action[1]);
		}
		else if (_stricmp(action[0].c_str(), "examine") == 0)
		{
			player.examineItem(action[1]);
		}
		else if (_stricmp(action[0].c_str(), "use") == 0)
		{
			player.useItem(action[1]);
		}
		else if (_stricmp(action[0].c_str(), "drop") == 0)
		{
			player.dropItem(action[1]);
		}
		else if (_stricmp(action[0].c_str(), "hello") == 0)
		{
			player.sayHello(action[1]);
		}
		else
			error = true;
	}
	else if (action.size() == 3) {

		error = false;
		if (_stricmp(action[0].c_str(), "put") == 0) 
		{
			player.putItem(action[1], action[2]);
		}
		else if (_stricmp(action[0].c_str(), "get") == 0)
		{
			player.getFrom(action[1], action[2]);
		}
		else if (_stricmp(action[0].c_str(), "open") == 0)
		{
			player.open(action[1], action[2]);
		}
		else
			error = true;
	}
	if(error)
		cout << "Incorrect comand type 'commands' for a list of posible comands\n";
}
