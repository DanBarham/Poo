#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Vec2.h"

class Dude
{
public:
	Dude( const Vec2& _pos = { 400.0f,300.0f } );
	void ClampToScreen();
	void Draw( Graphics& gfx ) const;
	void Update( const Keyboard& kbd );
	float GetX() const;
	float GetY() const;
	float GetWidth() const;
	float GetHeight() const;
	void Reset();
private:
	Vec2 pos;
	static constexpr float speed = 2.0f;
	static constexpr float width = 20.0f;		//Dimensions of the sprite
	static constexpr float height = 20.0f;
};