#include <string>
#include <vector>
#include "Map.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"

using namespace std;

Map::Map()
{
	string roomName = "Cantine";
	string description = "You find yourself in the cantine, it seems everybody left as quickly as possible, there is food rotting in the plates. There is a window you can see the darkness of space surrounding the spaceship. The room is well lit. You see a lighter and a pack cigarettes lying on a table.";
	vector<string> possibleDirections = { "east", "north" };
	vector<string> connectionType = { " a blody corridor", " a scratched corridor" };
	vector<string> roomNames = { "Hibernation chamber", "Control room" };
	Room room(roomName, description, possibleDirections, connectionType, roomNames);
	string name = "cigarettes";
	Item item(name, description);
	room.addItemInRoom(item);
	name = "lighter";
	Item item2(name, description);
	room.addItemInRoom(item2);
	roomsInMap.push_back(room);
	roomName = "Garbage Room";
	description = "You see piles of trash around you. The room is dimly lit but you can see a box of fireworks maybe they can be useful.";
	possibleDirections = { "west", "north" };
	connectionType = { " a pitch black corridor", " a slimey corridor"};
	roomNames = { "Hibernation Chamber", "Nest" };
	Room room2(roomName, description, possibleDirections, connectionType, roomNames);
	name = "fireworks";
	Item item3(name, description);
	room2.addItemInRoom(item3);
	roomsInMap.push_back(room2);
	roomName = "Nest";
	description = "You see broken eggs everywhere someone must have destroyed them. The room is pitch black but looking closely you can see a healthy egg. Beside the broken eggs you can see the captain's body with her key card around her neck. There is a vent in the room maybe you can acces it with the wrench";
	possibleDirections = { "south", "enter" };
	connectionType = { " a slimey corridor", "a vent" };
	roomNames = { "Garbage Room", "WorkShop" };
	Room room3(roomName, description, possibleDirections, connectionType, roomNames);
	name = "egg";
	Item item4(name, description);
	name = "key card";
	Item item5(name, description);
	room3.addItemInRoom(item4);
	room3.addItemInRoom(item5);
	roomsInMap.push_back(room3);
	roomName = "WorkShop";
	description = "You find yourself in the workshop all the doors are barricaded, there is a friendly robot looking at you. The room is well lit. You can see a backpack that can be useful fro carrying more items.";
	possibleDirections = { "enter"};
	connectionType = { "a vent"};
	roomNames = { "Nest"};
	Room room4(roomName, description, possibleDirections, connectionType, roomNames);
	name = "backpack";
	Item item6(name, description);
	room4.addItemInRoom(item6);
	roomsInMap.push_back(room4);
	roomName = "Control Room";
	description = "You find yourself in the control room, everything seems to be working fine you could do something to eliminate the alien. You see the cremation button to dispose of the garbage but you need a password to use it.";
	possibleDirections = { "south" };
	connectionType = {" a scratched corridor" };
	roomNames = { "Cantine" };
	Room room5(roomName, description, possibleDirections, connectionType, roomNames);
	roomsInMap.push_back(room5);
}

Room Map::getFirstRoom()
{
	string roomName = "Hibernation chamber";
	string description = "You find yourself in a hibernation chamber, everybody around you is dead. The only source of light is the flickering lights of the room. You can see a wrench on the floor.";
	vector<string> possibleDirections = { "west", "east" };
	vector<string> connectionType = { " a blody corridor", " a pitch black corridor" };
	vector<string> roomNames = { "Cantine", "Garbage Room" };
	Room room(roomName, description, possibleDirections, connectionType, roomNames);
	string name = "wrench";
	Item item(name, description);
	room.addItemInRoom(item);
	roomsInMap.push_back(room);
	return room;
}
