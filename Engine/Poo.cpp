#include "Poo.h"

Poo::Poo( Surface& _pooSprite,const Vec2& _pos,const Vec2& _vel )
	:
	pooSprite( _pooSprite ),
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
	gfx.DrawSprite( int( pos.x ),int( pos.y ),pooSprite.GetRect(),Graphics::GetScreenRect(),pooSprite );
}

bool Poo::IsEaten() const
{
	return isEaten;
}