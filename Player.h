#pragma once
#ifndef __Player__
#define __Player__
class Player
{
public:

	Player();
	void move();
	bool canMove();
	bool pickItem();
	bool dropItem();

};
#endif
