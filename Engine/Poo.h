#pragma once

#include "Graphics.h"
#include "Dude.h"

class Poo
{
public:
	Poo( const Vec2& _pos,const Vec2& _vel );
	void Update();
	void TestCollision( const Dude& dude );
	void Draw( Graphics& gfx ) const;
	bool IsEaten() const;
	void Reset( const Vec2& _pos,const Vec2& _vel );
private:
	Vec2 pos;
	Vec2 vel;
	static constexpr int width = 24;		//These are the dimensions of the sprite itself
	static constexpr int height = 24;
	bool isEaten = false;
	bool init = false;
};