#include "Dude.h"
#include "Graphics.h"

Dude::Dude( Surface& _dudeSprite,const Vec2& _pos )
	:
	dudeSprite( _dudeSprite ),
	pos( _pos )
{
}

float Dude::GetX() const
{
	return pos.x;
}

float Dude::GetY() const
{
	return pos.y;
}

float Dude::GetWidth() const
{
	return width;
}

float Dude::GetHeight() const
{
	return height;
}

void Dude::Update(const Keyboard& kbd)
{
	if ( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		pos.x += speed;
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		pos.x -= speed;
	}
	if ( kbd.KeyIsPressed( VK_DOWN ) )
	{
		pos.y += speed;
	}
	if ( kbd.KeyIsPressed( VK_UP ) )
	{
		pos.y -= speed;
	}
}

void Dude::ClampToScreen()
{
	const float right = pos.x + width;
	if( pos.x < 0.0f )
	{
		pos.x = 0.0f;
	}
	else if( right >= Graphics::ScreenWidth )
	{
		pos.x = ( Graphics::ScreenWidth - 1 ) - width;
	}

	const float bottom = pos.y + height;
	if( pos.y < 0.0f )
	{
		pos.y = 0.0f;
	}
	else if( bottom >= Graphics::ScreenHeight )
	{
		pos.y = ( Graphics::ScreenHeight - 1 ) - height;
	}
}

void Dude::Reset()
{
	pos.x = 400.0f;
	pos.y = 300.0f;
}

void Dude::Draw( Graphics& gfx ) const
{
	gfx.DrawSprite( int( pos.x ),int( pos.y ),dudeSprite.GetRect(),Graphics::GetScreenRect(),dudeSprite );
}
