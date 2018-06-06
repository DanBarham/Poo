#include "Pellet.h"
#include "Colors.h"

Pellet::Pellet(const Vec2& _pos)
	:
	pos( _pos )
{
}

void Pellet::ProcessConsumption(const Dude& dude)
{
	const float dudeRight = dude.GetX() + dude.GetWidth();
	const float dudeBottom = dude.GetY() + dude.GetHeight();
	const float pelletRight = pos.x + size;
	const float pelletBottom = pos.y + size;

	if ( dudeRight >= pos.x &&
		dude.GetX() <= pelletRight &&
		dudeBottom >= pos.y &&
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
			gfx.PutPixel( i + int( pos.x ),j + int( pos.y ),255,redShift,redShift );
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

void Pellet::Respawn( const Vec2& _pos )
{
	pos = _pos;
	ClampToScreen();
	isEaten = false;
}

void Pellet::ClampToScreen()
{
	const float right = pos.x + size;
	if ( pos.x < 0.0f )
	{
		pos.x = 0.0f;
	}
	else if ( right >= Graphics::ScreenWidth )
	{
		pos.x = ( Graphics::ScreenWidth - 1 ) - size;
	}

	const float bottom = pos.y + size;
	if ( pos.y < 0.0f )
	{
		pos.y = 0.0f;
	}
	else if ( bottom >= Graphics::ScreenHeight)
	{
		pos.y = ( Graphics::ScreenHeight - 1 ) - size;
	}
}