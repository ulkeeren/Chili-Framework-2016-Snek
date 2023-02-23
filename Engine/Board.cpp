#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(Location loc, const Color c)
{
	gfx.DrawRectDim(loc.x*dimension , loc.y*dimension, dimension-2, dimension-2, c);
}

int Board::getDim()
{
	return dimension;
}

void Board::DrawBorder()
{
	for (int a = 0; a < width; a++) {
		DrawBorderCellUp({a,0},Colors::Gray);
		DrawBorderCellDown({ a,59 }, Colors::Gray);
	}
	for (int b = 0; b < height; b++) {
		DrawBorderCellLeft({ 0,b }, Colors::Gray);
		DrawBorderCellRight({ 79,b }, Colors::Gray);
	}
}

void Board::DrawBorderCellUp(Location loc, const Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension/2, c);
}

void Board::DrawBorderCellDown(Location loc, const Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension+5, dimension, dimension / 2, c);
}

void Board::DrawBorderCellRight(Location loc, const Color c)
{
	gfx.DrawRectDim(loc.x * dimension+5, loc.y * dimension, dimension/2, dimension, c);
}

void Board::DrawBorderCellLeft(Location loc, const Color c)
{
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension/2, dimension
		, c);
}


