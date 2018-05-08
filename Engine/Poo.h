#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	void Update();
	void TestCollision( const Dude& dude );
	void Draw( Graphics& gfx ) const;
	bool IsEaten() const;
	void Init( const int _x,const int _y,const int _vx,const int _vy );
	void Reset(int _x, int _y, int _vx, int _vy);
private:
	int x;		//x postion
	int y;		//y position
	int vx;		//velocity in the x direction
	int vy;		// velocity in the y direction
	static constexpr int width = 24;		//These are the dimensions of the sprite itself
	static constexpr int height = 24;
	bool isEaten = false;
	bool init = false;
};