#pragma once

#include "Dude.h"
#include "Graphics.h"

class Pellet
{
public:
	void ProcessConsumption( const Dude& dude );
	void Draw( Graphics& gfx );
	bool IsEaten() const;
	void Respawn( const int _x,const int _y );
	void Init( const int _x,const int _y );
private:
	void ClampToScreen();
private:
	int x;		//x postion
	int y;		//y position
	int redShift = 255;
	bool redDown = true;
	static constexpr int redShiftSpeed = 3;
	static constexpr int size = 25;		//These are the dimensions of the sprite itself
	bool isEaten = false;
	bool init = false;
};