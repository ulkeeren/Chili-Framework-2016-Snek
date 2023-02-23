#pragma once
#include "Graphics.h"
#include "Location.h"
class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(Location loc,const Color c);
	int getDim();
	void DrawBorder();
	void DrawBorderCellUp(Location loc, const Color c);
	void DrawBorderCellDown(Location loc, const Color c);
	void DrawBorderCellRight(Location loc, const Color c);
	void DrawBorderCellLeft(Location loc, const Color c);

private:
	static constexpr int dimension = 10;
	static constexpr int width = (Graphics::ScreenWidth)/10;
	static constexpr int height = (Graphics::ScreenHeight)/10;
	Graphics& gfx;
};