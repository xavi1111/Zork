#include <iostream>
#include <string>
#include "TextParser.h"

using namespace std;

int main()
{
	string input;
	TextParser textParser;
	cout <<  "Welcome to Stelar!\n" ;

	while (1)
	{
		getline(cin, input);
		vector<string> parsedText = textParser.ParseText(input);
		textParser.checkAction(parsedText);
	}

	cout << "\nThanks for playing!\n";
	return 0;
}