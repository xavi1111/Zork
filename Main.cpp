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
	Room room = map.getCurrentRoom();
	Player player(&room);
	cout <<  "Welcome to Stelar!\n" ;

	while (1)
	{
		getline(cin, input);
		vector<string> parsedText = textParser.ParseText(input);
		if (parsedText.size() == 1 && _stricmp(parsedText[0].c_str(), "exit") == 0)
		{
			break;
		}
		else
			textParser.checkAction(parsedText, player, room);
		room = map.getCurrentRoom();
	}

	cout << "\nThanks for playing!\n";
	return 0;
}