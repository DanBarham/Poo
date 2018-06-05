#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Dude
{
public:
	void ClampToScreen();
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd );
	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;
	void Reset();
private:
	int x = 400;
	int y = 300;
	static constexpr int speed = 2;
	static constexpr int width = 20;		//Dimensions of the sprite
	static constexpr int height = 20;
};