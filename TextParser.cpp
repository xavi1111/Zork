#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "TextParser.h"

using namespace std;

TextParser::TextParser() {
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

	for (int i = 0; i < tokens.size(); i++)
		cout << tokens[i] << '\n';

	return tokens;
}

void TextParser::checkAction(const vector<string>& action)
{
	bool error = true;
	if (action.size() == 1)
	{
		error = false;
		if (_stricmp(action[0].c_str(), "north") == 0) {

		}
		else if (_stricmp(action[0].c_str(), "south") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "east") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "west") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "look") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "enter") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "hello") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "inventory") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "commands") == 0)
		{

		}
		else
			error = true;
	}
	else if (action.size() == 2)
	{
		error = false;
		if (_stricmp(action[0].c_str(), "take") == 0) {

		}
		else if (_stricmp(action[0].c_str(), "move") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "examine") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "drop") == 0)
		{

		}
		else
			error = true;
	}
	else if (action.size() == 3) {

		error = false;
		if (_stricmp(action[0].c_str(), "put") == 0) {

		}
		else if (_stricmp(action[0].c_str(), "take") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "open") == 0)
		{

		}
		else if (_stricmp(action[0].c_str(), "attack") == 0)
		{

		}
		else
			error = true;
	}
	if(error)
		cout << "Incorrect comand type 'comands' for a list of posible comands";
}
