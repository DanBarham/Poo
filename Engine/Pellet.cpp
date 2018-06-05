#include "Pellet.h"
#include "Colors.h"

Pellet::Pellet( const float _x,const float _y )
	:
	x( _x ),
	y( _y )
{
}

void Pellet::ProcessConsumption(const Dude& dude)
{
	const float dudeRight = dude.GetX() + dude.GetWidth();
	const float dudeBottom = dude.GetY() + dude.GetHeight();
	const float pelletRight = x + size;
	const float pelletBottom = y + size;

	if ( dudeRight >= x &&
		dude.GetX() <= pelletRight &&
		dudeBottom >= y &&
		dude.GetY() <= pelletBottom )
	{
		isEaten = true;
	}
}

void Pellet::Draw( Graphics& gfx )
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			gfx.PutPixel( i + int( x ),j + int( y ),255,redShift,redShift );
		}
	}

	if (redDown && redShift >= 0)
	{
		redShift -= redShiftSpeed;
		if (redShift <= 0)
		{
			redDown = false;
			redShift = 0;
		}
	}
	else
	{
		redShift += redShiftSpeed;
		if (redShift >= 255)
		{
			redDown = true;
			redShift = 255;
		}
	}
}

bool Pellet::IsEaten() const
{
	return isEaten;
}

void Pellet::Respawn( const float _x,const float _y )
{
	x = _x;
	y = _y;
	ClampToScreen();
	isEaten = false;
}

void Pellet::ClampToScreen()
{
	const float right = x + size;
	if ( x < 0.0f )
	{
		x = 0.0f;
	}
	else if ( right >= Graphics::ScreenWidth )
	{
		x = ( Graphics::ScreenWidth - 1 ) - size;
	}

	const float bottom = y + size;
	if ( y < 0.0f )
	{
		y = 0.0f;
	}
	else if ( bottom >= Graphics::ScreenHeight)
	{
		y = ( Graphics::ScreenHeight - 1 ) - size;
	}
}