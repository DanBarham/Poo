#pragma once

#include "Dude.h"
#include "Graphics.h"

class Pellet
{
public:
	Pellet( const Vec2& _pos );
	void ProcessConsumption( const Dude& dude );
	void Draw( Graphics& gfx );
	bool IsEaten() const;
	void Respawn( const Vec2& _pos );
private:
	void ClampToScreen();
private:
	Vec2 pos;
	int redShift = 255;
	bool redDown = true;
	static constexpr int redShiftSpeed = 3;
	static constexpr int size = 20;		//These are the dimensions of the sprite itself
	bool isEaten = false;
	bool init = false;
};