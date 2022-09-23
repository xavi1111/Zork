#include <iostream>
#include <string>
#include "TextParser.h"
#include "Player.h"
#include "Room.h"
#include "Map.h"

using namespace std;

int main()
{
	string input;
	TextParser textParser;
	Map map;
	Player player;
	player.map = map;
	cout <<  "Welcome to Stelar!\n" ;
	player.currentRoom->getInfo();
	string name = "backpack";
	string description = "The items in the backpack are : \n";
	Backpack backpackAux(name, description);
	player.backpack = &backpackAux;

	while (1)
	{
		getline(cin, input);
		vector<string> parsedText = textParser.ParseText(input);
		if (parsedText.size() == 1 && _stricmp(parsedText[0].c_str(), "exit") == 0)
		{
			break;
		}
		else
			textParser.checkAction(parsedText, player);

		if (player.finishedGame)
			break;
	}

	cout << "\nThanks for playing!\n";
	return 0;
}