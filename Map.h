#pragma once
#ifndef __Map__
#define __Map__
#include <string>
#include <vector>
#include "Room.h"

using namespace std;

class Map
{
public:
	Map();
	vector<Room> roomsInMap;
};
#endif