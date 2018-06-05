#pragma once

#include "Dude.h"
#include "Graphics.h"

class Pellet
{
public:
	Pellet( const float _x,const float _y );
	void ProcessConsumption( const Dude& dude );
	void Draw( Graphics& gfx );
	bool IsEaten() const;
	void Respawn( const float _x,const float _y );
private:
	void ClampToScreen();
private:
	float x;		//x postion
	float y;		//y position
	int redShift = 255;
	bool redDown = true;
	static constexpr int redShiftSpeed = 3;
	static constexpr int size = 25;		//These are the dimensions of the sprite itself
	bool isEaten = false;
	bool init = false;
};