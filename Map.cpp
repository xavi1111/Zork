#include <string>
#include <vector>
#include "Map.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "Backpack.h"

using namespace std;

Map::Map()
{
	string roomName = "Hibernation chamber";
	string description = "You find yourself in a hibernation chamber, everybody around you is dead. The only source of light is the flickering lights of the room. You can see a wrench on the floor.";
	vector<string> possibleDirections = { "west", "east" };
	vector<string> connectionType = { " a blody corridor", " a pitch black corridor" };
	vector<string> roomNames = { "Cantine", "Garbage Room" };
	vector<bool> entranceLocked = { false, false };
	vector<string> itemNeded = { " ", " " };
	vector<string> itemBlocked = { " ", " " };
	Room room6(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	string name = "wrench";
	Item item7(name, description);
	room6.addItemInRoom(item7);
	roomsInMap.push_back(room6);
	roomName = "Cantine";
	description = "You find yourself in the cantine, it seems everybody left as quickly as possible, there is food rotting in the plates. There is a window you can see the darkness of space surrounding the spaceship. The room is well lit. You see a lighter and a pack cigarettes lying on a table.";
	possibleDirections = { "east", "north" };
	connectionType = { " a blody corridor", " a scratched corridor" };
	roomNames = { "Hibernation chamber", "Control room" };
	entranceLocked = { false, true};
	itemNeded = { " ", "keycard" };
	itemBlocked = { " ", "door" };
	Room room(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "cigarettes";
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
	entranceLocked = { false, false };
	itemNeded = { " ", " " };
	itemBlocked = { " ", " " };
	Room room2(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "fireworks";
	Item item3(name, description);
	room2.addItemInRoom(item3);
	roomsInMap.push_back(room2);
	roomName = "Nest";
	description = "You see broken eggs everywhere someone must have destroyed them. The room is pitch black but looking closely you can see a healthy egg. Beside the broken eggs you can see the captain's body with her keycard around her neck. There is a vent in the room maybe you can acces it with the wrench";
	possibleDirections = { "south", "north" };
	connectionType = { " a slimey corridor", " a vent" };
	roomNames = { "Garbage Room", "WorkShop" };
	entranceLocked = { false, true};
	itemNeded = { " ", "wrench" };
	itemBlocked = { " ", "vent" };
	Room room3(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "egg";
	Item item4(name, description);
	name = "keycard";
	Item item5(name, description);
	room3.addItemInRoom(item4);
	room3.addItemInRoom(item5);
	roomsInMap.push_back(room3);
	roomName = "WorkShop";
	description = "You find yourself in the workshop all the doors are barricaded, there is a friendly robot looking at you. The room is well lit. You can see a backpack that can be useful fro carrying more items.";
	possibleDirections = { "south"};
	connectionType = { " a vent"};
	roomNames = { "Nest"};
	entranceLocked = { false };
	itemNeded = { " " };
	itemBlocked = { " "};
	Room room4(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	room4.hasBackpack = true;
	string robotName = "robot";
	vector<string> answers = { "All the crew was killed by the alien I'm surprised that you are alive\n", "I hid here because i was to afraid to do anything\n", "The password for the incinerator is 2309\n" };
	vector<string> possibleCommands = { "1", "2", "3" };
	vector<string> keyWords = { "Crew", "You", "Password" };
	NPC npc(robotName, answers, possibleCommands, keyWords);
	room4.addNPC(npc);
	roomsInMap.push_back(room4);
	roomName = "Control Room";
	description = "You find yourself in the control room, everything seems to be working fine you could do something to eliminate the alien. You see the cremation button to dispose of the garbage but you need a password to use it.";
	possibleDirections = { "south" };
	connectionType = {" a scratched corridor" };
	roomNames = { "Cantine" };
	entranceLocked = { false };
	itemNeded = { " " };
	itemBlocked = { " " };
	Room room5(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	roomsInMap.push_back(room5);
}
