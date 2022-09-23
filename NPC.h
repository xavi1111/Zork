#pragma once
#ifndef __NPC__
#define __NPC__
#include <string>
#include <vector>

using namespace std;

class NPC
{
public:
	NPC(string& name, vector<string>& answers, vector<string>& possibleCommands, vector<string>& keyWords);
	void converstionLoop();
	string name;
	vector<string> answers;
	vector<string> possibleCommands;
	vector<string> keyWords;
public:

};

#endif 