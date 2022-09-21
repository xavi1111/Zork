#include <string>
#include "Map.h"
#include "Room.h"
#include "Item.h"
using namespace std;

Map::Map()
{
	return;
}

Room Map::getCurrentRoom() const
{
	string description = "aa";
	Room room(description);
	string name = "wrench";
	Item item(name, description);
	room.addItemInRoom(item);
	return room;
}
