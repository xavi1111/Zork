#include <string>
#include "Map.h"
#include "Room.h"

Map::Map()
{
	return;
}

Room Map::getCurrentRoom() const
{
	string description = "aa";
	Room room(description);
	return room;
}
