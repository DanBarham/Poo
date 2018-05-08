#include "ScoreBoard.h"
#include "Colors.h"

void ScoreBoard::Draw(int score, Graphics & gfx) const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < score * 15; ++j)
		{
			gfx.PutPixel(j + 15, i + 15, Colors::Blue);
		}
	}
}