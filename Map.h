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
	Room getFirstRoom();
	vector<Room> roomsInMap;
};
#endif