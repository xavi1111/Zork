#include <string>
#include <vector>
#include <iostream>
#include "NPC.h"

NPC::NPC(string& name, vector<string>& answers, vector<string>& possibleCommands, vector<string>& keyWords)
{
	NPC::name = name;
	NPC::answers = answers;
	NPC::possibleCommands = possibleCommands;
	NPC::keyWords = keyWords;
}

void NPC::converstionLoop()
{
	string action;
	cout << "Hello you are alive! My name is Jarvis. \n";
	while (1) 
	{
		cout << "Anything else you want to know : \n";
		for (int i = 0; i < keyWords.size(); i++) 
		{
			cout << possibleCommands[i] << ") " << keyWords[i] << "\n";
		}
		cout << "e) Exit\n";
		cin >> action;
		for (int i = 0; i < possibleCommands.size(); i++)
		{
			if (_stricmp(possibleCommands[i].c_str(), action.c_str()) == 0) 
			{
				cout << answers[i] << "\n";
			}
		}
		if (_stricmp("e", action.c_str()) == 0)
			break;
	}
	cout << "Bye and good luck! \n";
}
