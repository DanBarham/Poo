#pragma once

#include "Graphics.h"

class ScoreBoard
{
public:
	void Draw( int score,Graphics& gfx ) const;
private:
	static constexpr int height = 30;
};
