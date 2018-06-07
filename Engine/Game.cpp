/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::~Game()
{
	delete dude;
	dude = nullptr;
}

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ), 
	rng( rd() ),
	xDist( 0.0f,770.0f ),
	yDist( 0.0f,570.0f ),
	pooVDist( -1.5f,1.5f ),
	dudeSprite( "Images\\awsom.bmp" ),
	titleSprite( "Images\\dapoopoo.bmp" ),
	pooSprite( "Images\\poo.bmp" ),
	gameOverSprite( "Images\\game_over.bmp" ),
	pellet( Vec2( xDist( rng ),yDist( rng ) ) ),
	gState( GameState::TitleScreen ),
	pooSound( L"Sound\\fart.wav" ),
	gameLoop( L"Sound\\loop.wav",0.0f,13.60f ),
	chime( L"Sound\\chime.wav" ),
	score( 0 )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	switch( gState )
	{
	case GameState::TitleScreen:
		while( !wnd.kbd.KeyIsEmpty() )
		{
			auto e = wnd.kbd.ReadKey();

			if( e.IsRelease() )
			{
				if( e.GetCode() == VK_RETURN )
				{
					SpawnGameAssets();
					gameLoop.Play();
					gState = GameState::Playing;
				}
			}
		}
		break;
	case GameState::Playing:
		dude->Update( wnd.kbd );
		dude->ClampToScreen();

		if ( pellet.IsEaten() )
		{
			if( score < maxScore )
			{
				++score;
			}
			pellet.Respawn( Vec2( xDist( rng ),yDist( rng ) ) );
			SpawnPoo();
			chime.Play();
		}

		pellet.ProcessConsumption( *dude );

		for( Poo& p : poo )
		{
			p.Update();
			p.TestCollision( *dude );
			if( p.IsEaten() )
			{
				gameLoop.StopAll();
				pooSound.Play();
				gState = GameState::GameOver;
			}
		}
		break;
	case GameState::GameOver:
		while( !wnd.kbd.KeyIsEmpty() )
		{
			auto e = wnd.kbd.ReadKey();

			if( e.IsRelease() )
			{
				if( e.GetCode() == VK_RETURN )
				{
					gState = GameState::TitleScreen;
					SpawnGameAssets();
				}
			}
		}
		break;
	}
}

void Game::ComposeFrame()
{
	if( gState == GameState::TitleScreen )
	{
		DrawTitleScreen( 275,75 );
	}
	else
	{
		if ( gState == GameState::GameOver )
		{
			DrawGameOver( 350,250 );	//wompwomp
		}

		dude->Draw( gfx );
		pellet.Draw( gfx );
		sBoard.Draw(score, gfx);
		for( const Poo& p : poo )
		{
			p.Draw( gfx );
		}	
	}
}

void Game::SpawnGameAssets()
{
	delete dude;
	dude = new Dude( dudeSprite );

	const int numPoo = 10;
	poo.clear();

	for( int i = 0; i < numPoo; ++i )
	{
		SpawnPoo();
	}
	score = 0;
	gState = GameState::TitleScreen;
}

void Game::SpawnPoo()
{
	Vec2 vel;
	Vec2 pos;
	const Vec2 dudePos = Vec2( dude->GetX(),dude->GetY() );
	const float minDistanceSq = 20000.0f;
	float distanceSq;

	do
	{
		vel.x = pooVDist( rng );
		vel.y = pooVDist( rng );
		pos.x = xDist( rng );
		pos.y = yDist( rng );
		distanceSq = ( dudePos - pos ).GetLengthSq();
	} while ( abs( vel.x ) < 0.5f || abs( vel.y ) < 0.5f || distanceSq < minDistanceSq );

	poo.emplace_back( pooSprite,pos,vel );
}

void Game::DrawTitleScreen( int x,int y )
{
	gfx.DrawSprite( x,y,titleSprite.GetRect(),Graphics::GetScreenRect(),titleSprite );
}

void Game::DrawGameOver( int x,int y )
{
	gfx.DrawSprite( x,y,gameOverSprite.GetRect(),Graphics::GetScreenRect(),gameOverSprite );
}