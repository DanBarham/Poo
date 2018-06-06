#include "Poo.h"

Poo::Poo( const Vec2& _pos,const Vec2& _vel )
	:
	pos( _pos ),
	vel( _vel )
{
}

void Poo::Update()
{
	pos.x += vel.x;
	pos.y += vel.y;

	const float right = pos.x + width;
	if( pos.x < 0 )
	{
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if( right >= Graphics::ScreenWidth )
	{
		pos.x = (Graphics::ScreenWidth - 1) - width;
		vel.x = -vel.x;
	}

	const float bottom = pos.y + height;
	if( pos.y < 0 )
	{
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if( bottom >= Graphics::ScreenHeight )
	{
		pos.y = (Graphics::ScreenHeight - 1) - height;
		vel.y = -vel.y;
	}
}

void Poo::TestCollision( const Dude& dude )
{
	const float duderight = dude.GetX() + dude.GetWidth();
	const float dudebottom = dude.GetY() + dude.GetHeight();
	const float pooright = pos.x + width;
	const float poobottom = pos.y + height;

	if( duderight >= pos.x &&
		dude.GetX() <= pooright &&
		dudebottom >= pos.y &&
		dude.GetY() <= poobottom )
	{
		isEaten = true;
	}
}

void Poo::Reset( const Vec2& _pos,const Vec2& _vel )
{
	pos = _pos;
	vel = _vel;
	isEaten = false;
}

void Poo::Draw( Graphics& gfx ) const
{
	gfx.PutPixel( 14 + int( pos.x ),0 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 7 + int( pos.x ),1 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),1 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 20 + int( pos.x ),1 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),2 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),2 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 20 + int( pos.x ),2 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),3 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),4 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),4 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 21 + int( pos.x ),4 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 7 + int( pos.x ),5 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),5 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 21 + int( pos.x ),5 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 7 + int( pos.x ),6 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 20 + int( pos.x ),6 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),7 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),7 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),7 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),7 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),8 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),8 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 14 + int( pos.x ),8 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),9 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),9 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),9 + int( pos.y ),102,57,0 );
	gfx.PutPixel( 13 + int( pos.x ),9 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),9 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),9 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 21 + int( pos.x ),9 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 10 + int( pos.x ),10 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 11 + int( pos.x ),10 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),10 + int( pos.y ),102,57,0 );
	gfx.PutPixel( 13 + int( pos.x ),10 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),10 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),10 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),10 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 9 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),11 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),11 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 14 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 16 + int( pos.x ),11 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),12 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),12 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),12 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),12 + int( pos.y ),111,62,0 );
	gfx.PutPixel( 13 + int( pos.x ),12 + int( pos.y ),102,57,0 );
	gfx.PutPixel( 14 + int( pos.x ),12 + int( pos.y ),102,57,0 );
	gfx.PutPixel( 15 + int( pos.x ),12 + int( pos.y ),102,57,0 );
	gfx.PutPixel( 16 + int( pos.x ),12 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),13 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),13 + int( pos.y ),109,61,0 );
	gfx.PutPixel( 11 + int( pos.x ),13 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),13 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),13 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),13 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),13 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),13 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 5 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 8 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 11 + int( pos.x ),14 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),14 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),14 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),14 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),14 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),14 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 4 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 5 + int( pos.x ),15 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),15 + int( pos.y ),116,65,0 );
	gfx.PutPixel( 8 + int( pos.x ),15 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 9 + int( pos.x ),15 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 10 + int( pos.x ),15 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 14 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 16 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 17 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 18 + int( pos.x ),15 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 2 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 3 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 4 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 5 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),16 + int( pos.y ),116,65,0 );
	gfx.PutPixel( 8 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 9 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 10 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),16 + int( pos.y ),109,61,0 );
	gfx.PutPixel( 14 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 17 + int( pos.x ),16 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 18 + int( pos.x ),16 + int( pos.y ),123,69,0 );
	gfx.PutPixel( 19 + int( pos.x ),16 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 0 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),17 + int( pos.y ),87,49,0 );
	gfx.PutPixel( 2 + int( pos.x ),17 + int( pos.y ),87,49,0 );
	gfx.PutPixel( 3 + int( pos.x ),17 + int( pos.y ),87,49,0 );
	gfx.PutPixel( 4 + int( pos.x ),17 + int( pos.y ),87,49,0 );
	gfx.PutPixel( 5 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 6 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),17 + int( pos.y ),43,24,0 );
	gfx.PutPixel( 8 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 11 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),17 + int( pos.y ),40,22,0 );
	gfx.PutPixel( 14 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),17 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),17 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 17 + int( pos.x ),17 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 18 + int( pos.x ),17 + int( pos.y ),123,69,0 );
	gfx.PutPixel( 19 + int( pos.x ),17 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 0 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 2 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 3 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 4 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 5 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 6 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 8 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 11 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 14 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 17 + int( pos.x ),18 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 18 + int( pos.x ),18 + int( pos.y ),123,69,0 );
	gfx.PutPixel( 19 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 21 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 22 + int( pos.x ),18 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 0 + int( pos.x ),19 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 2 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 3 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 4 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 5 + int( pos.x ),19 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 6 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 7 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 8 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 9 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 10 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 17 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 18 + int( pos.x ),19 + int( pos.y ),123,69,0 );
	gfx.PutPixel( 19 + int( pos.x ),19 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 21 + int( pos.x ),19 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 22 + int( pos.x ),19 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 23 + int( pos.x ),19 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 2 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 3 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 4 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 5 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 6 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 7 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 8 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 9 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 10 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 11 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 12 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 13 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 14 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 15 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 16 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 17 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 18 + int( pos.x ),20 + int( pos.y ),123,69,0 );
	gfx.PutPixel( 19 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 21 + int( pos.x ),20 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 22 + int( pos.x ),20 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 23 + int( pos.x ),20 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 0 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),21 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 2 + int( pos.x ),21 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 3 + int( pos.x ),21 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 4 + int( pos.x ),21 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 5 + int( pos.x ),21 + int( pos.y ),138,77,0 );
	gfx.PutPixel( 6 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 7 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 8 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 9 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 10 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 11 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 12 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 13 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 14 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 15 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 16 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 17 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 18 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 20 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 21 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 22 + int( pos.x ),21 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 0 + int( pos.x ),22 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),22 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 2 + int( pos.x ),22 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 3 + int( pos.x ),22 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 4 + int( pos.x ),22 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 5 + int( pos.x ),22 + int( pos.y ),65,36,0 );
	gfx.PutPixel( 6 + int( pos.x ),22 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 1 + int( pos.x ),23 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 2 + int( pos.x ),23 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 3 + int( pos.x ),23 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 4 + int( pos.x ),23 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 5 + int( pos.x ),23 + int( pos.y ),51,28,0 );
	gfx.PutPixel( 6 + int( pos.x ),23 + int( pos.y ),51,28,0 );
}

bool Poo::IsEaten() const
{
	return isEaten;
}