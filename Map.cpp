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
	string description = "You find yourself in a hibernation chamber, everybody around you is dead. The only source of light is the flickering lights of the room.";
	vector<string> possibleDirections = { "west", "east" };
	vector<string> connectionType = { " a blody corridor", " a pitch black corridor" };
	vector<string> roomNames = { "Cantine", "Garbage Room" };
	vector<bool> entranceLocked = { false, false };
	vector<string> itemNeded = { " ", " " };
	vector<string> itemBlocked = { " ", " " };
	Room room(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	string name = "wrench";
	string itemDescription = "The wrench is bloody but it seems fine.";
	string roomDescription = "You can see a wrench on the floor.";
	Item item(name, description, roomDescription);
	room.addItemInRoom(item);
	roomsInMap.push_back(room);
	roomName = "Cantine";
	description = "You find yourself in the cantine, it seems everybody left as quickly as possible, there is food rotting in the plates. There is a window you can see the darkness of space surrounding the spaceship. The room is well lit.";
	possibleDirections = { "east", "north" };
	connectionType = { " a blody corridor", " a scratched corridor" };
	roomNames = { "Hibernation chamber", "Control room" };
	entranceLocked = { false, true};
	itemNeded = { " ", "keycard" };
	itemBlocked = { " ", "door" };
	Room room2(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "cigarettes";
	itemDescription = "The pack is intact and all the cigarettes are in good shape.";
	roomDescription = "You see a pack of cigarettes lying on the floor.";
	Item item2(name, description, roomDescription);
	room2.addItemInRoom(item2);
	name = "lighter";
	itemDescription = "The lighter is in perfect conditions it is as good as new.";
	roomDescription = "You see a lighter lying on the floor.";
	Item item3(name, description, roomDescription);
	room2.addItemInRoom(item3);
	roomsInMap.push_back(room2);
	roomName = "Garbage Room";
	description = "You see piles of trash around you. The room is dimly lit.";
	possibleDirections = { "west", "north" };
	connectionType = { " a pitch black corridor", " a slimey corridor"};
	roomNames = { "Hibernation Chamber", "Nest" };
	entranceLocked = { false, false };
	itemNeded = { " ", " " };
	itemBlocked = { " ", " " };
	Room room3(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "fireworks";
	itemDescription = "The box is dirty but the fireworks inside are in perfect condition.";
	roomDescription = "You can see a box of fireworks maybe they can be useful.";
	Item item4(name, description, roomDescription);
	room3.addItemInRoom(item4);
	roomsInMap.push_back(room3);
	roomName = "Nest";
	description = "You see broken eggs everywhere someone must have destroyed them. The room is pitch black. Beside the broken eggs you can see the captain's body. There is a vent in the room maybe you can acces it with the wrench";
	possibleDirections = { "south", "north" };
	connectionType = { " a slimey corridor", " a vent" };
	roomNames = { "Garbage Room", "WorkShop" };
	entranceLocked = { false, true};
	itemNeded = { " ", "wrench" };
	itemBlocked = { " ", "vent" };
	Room room4(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	name = "egg";
	itemDescription = "The egg pulsates and you can see something moving inside.";
	roomDescription = "You can see an alien egg that is not destroyed.";
	Item item5(name, description, roomDescription);
	name = "keycard";
	itemDescription = "The keycard is covered in blood but it is in good shape.";
	roomDescription = "You can see a keycard lying around.";
	Item item6(name, description, roomDescription);
	room4.addItemInRoom(item5);
	room4.addItemInRoom(item6);
	room4.hasAlien = true;
	roomsInMap.push_back(room4);
	roomName = "WorkShop";
	description = "You find yourself in the workshop all the doors are barricaded, there is a friendly robot looking at you. The room is well lit.";
	possibleDirections = { "south"};
	connectionType = { " a vent"};
	roomNames = { "Nest"};
	entranceLocked = { false };
	itemNeded = { " " };
	itemBlocked = { " "};
	Room room5(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	room5.hasBackpack = true;
	string robotName = "robot";
	vector<string> answers = { "All the crew was killed by the alien I'm surprised that you are alive\n", "I hid here because i was to afraid to do anything\n", "The password for the incinerator is 2309\n", "The alien makes sure the egg is safe maybe if you drop it in the garbage room that would lure the alien and you could incinerate it.\n" };
	vector<string> possibleCommands = { "1", "2", "3", "4" };
	vector<string> keyWords = { "Crew", "You", "Password", "Egg" };
	NPC npc(robotName, answers, possibleCommands, keyWords);
	room5.addNPC(npc);
	roomsInMap.push_back(room5);
	roomName = "Control Room";
	description = "You find yourself in the control room, everything seems to be working fine you could do something to eliminate the alien. You see the incieration button to dispose of the garbage but you need a password to use it.";
	possibleDirections = { "south" };
	connectionType = {" a scratched corridor" };
	roomNames = { "Cantine" };
	entranceLocked = { false };
	itemNeded = { " " };
	itemBlocked = { " " };
	Room room6(roomName, description, possibleDirections, connectionType, roomNames, entranceLocked, itemNeded, itemBlocked);
	room6.hasEndingButton = true;
	roomsInMap.push_back(room6);
}
