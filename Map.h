#pragma once
#ifndef __Map__
#define __Map__
#include <string>
#include "Room.h"

class Map
{
public:
	Map();
	Room getCurrentRoom() const;
};
#endif