#include "Pellet.h"
#include "Colors.h"
#include <assert.h>

void Pellet::ProcessConsumption(const Dude& dude)
{
	assert(init);
	const int dudeRight = dude.GetX() + dude.GetWidth();
	const int dudeBottom = dude.GetY() + dude.GetHeight();
	const int pelletRight = x + size;
	const int pelletBottom = y + size;

	if (dudeRight >= x &&
		dude.GetX() <= pelletRight &&
		dudeBottom >= y &&
		dude.GetY() <= pelletBottom)
	{
		isEaten = true;
	}
}

void Pellet::Draw( Graphics& gfx )
{
	assert(init);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			gfx.PutPixel( i + x,j + y,255,redShift,redShift );
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
	assert(init);
	return isEaten;
}

void Pellet::Respawn( const int _x,const int _y )
{
	assert(init);
	x = _x;
	y = _y;
	ClampToScreen();
	isEaten = false;
}

void Pellet::ClampToScreen()
{
	assert(init);
	const int right = x + size;
	if (x < 0)
	{
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - size;
	}

	const int bottom = y + size;
	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - size;
	}
}

void Pellet::Init( const int _x,const int _y )
{
	assert(!init);
	init = true;
	Respawn( _x,_y );	
}