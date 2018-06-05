#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	Poo( const float _x,const float _y,const float _vx,const float _vy );
	void Update();
	void TestCollision( const Dude& dude );
	void Draw( Graphics& gfx ) const;
	bool IsEaten() const;
	void Reset( float _x,float _y,float _vx,float _vy );
private:
	float x;		//x postion
	float y;		//y position
	float vx;		//velocity in the x direction
	float vy;		// velocity in the y direction
	static constexpr int width = 24;		//These are the dimensions of the sprite itself
	static constexpr int height = 24;
	bool isEaten = false;
	bool init = false;
};