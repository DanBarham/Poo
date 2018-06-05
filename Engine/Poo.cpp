#include "Poo.h"

Poo::Poo( const float _x,const float _y,const float _vx,const float _vy )
	:
	x( _x ),
	y( _y ),
	vx( _vx ),
	vy( _vy )
{
}

void Poo::Update()
{
	x += vx;
	y += vy;

	const float right = x + width;
	if( x < 0 )
	{
		x = 0;
		vx = -vx;
	}
	else if( right >= Graphics::ScreenWidth )
	{
		x = (Graphics::ScreenWidth - 1) - width;
		vx = -vx;
	}

	const float bottom = y + height;
	if( y < 0 )
	{
		y = 0;
		vy = -vy;
	}
	else if( bottom >= Graphics::ScreenHeight )
	{
		y = (Graphics::ScreenHeight - 1) - height;
		vy = -vy;
	}
}

void Poo::TestCollision( const Dude& dude )
{
	const float duderight = dude.GetX() + dude.GetWidth();
	const float dudebottom = dude.GetY() + dude.GetHeight();
	const float pooright = x + width;
	const float poobottom = y + height;

	if( duderight >= x &&
		dude.GetX() <= pooright &&
		dudebottom >= y &&
		dude.GetY() <= poobottom )
	{
		isEaten = true;
	}
}

void Poo::Reset( float _x,float _y,float _vx,float _vy )
{
	x = _x;
	y = _y;
	vx = _vx;
	vy = _vy;
	isEaten = false;
}

void Poo::Draw( Graphics& gfx ) const
{
	gfx.PutPixel( 14 + int( x ),0 + int( y ),138,77,0 );
	gfx.PutPixel( 7 + int( x ),1 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),1 + int( y ),138,77,0 );
	gfx.PutPixel( 20 + int( x ),1 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),2 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),2 + int( y ),138,77,0 );
	gfx.PutPixel( 20 + int( x ),2 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),3 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),4 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),4 + int( y ),138,77,0 );
	gfx.PutPixel( 21 + int( x ),4 + int( y ),138,77,0 );
	gfx.PutPixel( 7 + int( x ),5 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),5 + int( y ),138,77,0 );
	gfx.PutPixel( 21 + int( x ),5 + int( y ),138,77,0 );
	gfx.PutPixel( 7 + int( x ),6 + int( y ),138,77,0 );
	gfx.PutPixel( 20 + int( x ),6 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),7 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),7 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),7 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),7 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),8 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),8 + int( y ),51,28,0 );
	gfx.PutPixel( 14 + int( x ),8 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),9 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),9 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),9 + int( y ),102,57,0 );
	gfx.PutPixel( 13 + int( x ),9 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),9 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),9 + int( y ),51,28,0 );
	gfx.PutPixel( 21 + int( x ),9 + int( y ),138,77,0 );
	gfx.PutPixel( 10 + int( x ),10 + int( y ),51,28,0 );
	gfx.PutPixel( 11 + int( x ),10 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),10 + int( y ),102,57,0 );
	gfx.PutPixel( 13 + int( x ),10 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),10 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),10 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),10 + int( y ),138,77,0 );
	gfx.PutPixel( 9 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),11 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),11 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 14 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 16 + int( x ),11 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),12 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),12 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),12 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),12 + int( y ),111,62,0 );
	gfx.PutPixel( 13 + int( x ),12 + int( y ),102,57,0 );
	gfx.PutPixel( 14 + int( x ),12 + int( y ),102,57,0 );
	gfx.PutPixel( 15 + int( x ),12 + int( y ),102,57,0 );
	gfx.PutPixel( 16 + int( x ),12 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),13 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),13 + int( y ),109,61,0 );
	gfx.PutPixel( 11 + int( x ),13 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),13 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),13 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),13 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),13 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),13 + int( y ),51,28,0 );
	gfx.PutPixel( 5 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 8 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 11 + int( x ),14 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),14 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),14 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),14 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),14 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),14 + int( y ),51,28,0 );
	gfx.PutPixel( 4 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 5 + int( x ),15 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),15 + int( y ),116,65,0 );
	gfx.PutPixel( 8 + int( x ),15 + int( y ),138,77,0 );
	gfx.PutPixel( 9 + int( x ),15 + int( y ),138,77,0 );
	gfx.PutPixel( 10 + int( x ),15 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 14 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 16 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 17 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 18 + int( x ),15 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 2 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 3 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 4 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 5 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),16 + int( y ),116,65,0 );
	gfx.PutPixel( 8 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 9 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 10 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),16 + int( y ),109,61,0 );
	gfx.PutPixel( 14 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 17 + int( x ),16 + int( y ),138,77,0 );
	gfx.PutPixel( 18 + int( x ),16 + int( y ),123,69,0 );
	gfx.PutPixel( 19 + int( x ),16 + int( y ),51,28,0 );
	gfx.PutPixel( 0 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),17 + int( y ),87,49,0 );
	gfx.PutPixel( 2 + int( x ),17 + int( y ),87,49,0 );
	gfx.PutPixel( 3 + int( x ),17 + int( y ),87,49,0 );
	gfx.PutPixel( 4 + int( x ),17 + int( y ),87,49,0 );
	gfx.PutPixel( 5 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 6 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),17 + int( y ),43,24,0 );
	gfx.PutPixel( 8 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 11 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),17 + int( y ),40,22,0 );
	gfx.PutPixel( 14 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),17 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),17 + int( y ),138,77,0 );
	gfx.PutPixel( 17 + int( x ),17 + int( y ),138,77,0 );
	gfx.PutPixel( 18 + int( x ),17 + int( y ),123,69,0 );
	gfx.PutPixel( 19 + int( x ),17 + int( y ),51,28,0 );
	gfx.PutPixel( 0 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 2 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 3 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 4 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 5 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 6 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 8 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 11 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 14 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 17 + int( x ),18 + int( y ),138,77,0 );
	gfx.PutPixel( 18 + int( x ),18 + int( y ),123,69,0 );
	gfx.PutPixel( 19 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 21 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 22 + int( x ),18 + int( y ),51,28,0 );
	gfx.PutPixel( 0 + int( x ),19 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 2 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 3 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 4 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 5 + int( x ),19 + int( y ),51,28,0 );
	gfx.PutPixel( 6 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 7 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 8 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 9 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 10 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 17 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 18 + int( x ),19 + int( y ),123,69,0 );
	gfx.PutPixel( 19 + int( x ),19 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 21 + int( x ),19 + int( y ),138,77,0 );
	gfx.PutPixel( 22 + int( x ),19 + int( y ),65,36,0 );
	gfx.PutPixel( 23 + int( x ),19 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 2 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 3 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 4 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 5 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 6 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 7 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 8 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 9 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 10 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 11 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 12 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 13 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 14 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 15 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 16 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 17 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 18 + int( x ),20 + int( y ),123,69,0 );
	gfx.PutPixel( 19 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 21 + int( x ),20 + int( y ),138,77,0 );
	gfx.PutPixel( 22 + int( x ),20 + int( y ),65,36,0 );
	gfx.PutPixel( 23 + int( x ),20 + int( y ),51,28,0 );
	gfx.PutPixel( 0 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),21 + int( y ),138,77,0 );
	gfx.PutPixel( 2 + int( x ),21 + int( y ),138,77,0 );
	gfx.PutPixel( 3 + int( x ),21 + int( y ),138,77,0 );
	gfx.PutPixel( 4 + int( x ),21 + int( y ),138,77,0 );
	gfx.PutPixel( 5 + int( x ),21 + int( y ),138,77,0 );
	gfx.PutPixel( 6 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 7 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 8 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 9 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 10 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 11 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 12 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 13 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 14 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 15 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 16 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 17 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 18 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 20 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 21 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 22 + int( x ),21 + int( y ),51,28,0 );
	gfx.PutPixel( 0 + int( x ),22 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),22 + int( y ),65,36,0 );
	gfx.PutPixel( 2 + int( x ),22 + int( y ),65,36,0 );
	gfx.PutPixel( 3 + int( x ),22 + int( y ),65,36,0 );
	gfx.PutPixel( 4 + int( x ),22 + int( y ),65,36,0 );
	gfx.PutPixel( 5 + int( x ),22 + int( y ),65,36,0 );
	gfx.PutPixel( 6 + int( x ),22 + int( y ),51,28,0 );
	gfx.PutPixel( 1 + int( x ),23 + int( y ),51,28,0 );
	gfx.PutPixel( 2 + int( x ),23 + int( y ),51,28,0 );
	gfx.PutPixel( 3 + int( x ),23 + int( y ),51,28,0 );
	gfx.PutPixel( 4 + int( x ),23 + int( y ),51,28,0 );
	gfx.PutPixel( 5 + int( x ),23 + int( y ),51,28,0 );
	gfx.PutPixel( 6 + int( x ),23 + int( y ),51,28,0 );
}

bool Poo::IsEaten() const
{
	return isEaten;
}