#include "Board.h"
#include "Objective.h"
Board::Board(Graphics& gfx)
	:
	gfx(gfx),
	rng(rd()),
	xDist(2,79),
	yDist(2,59)
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

int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

bool Board::checkPoisonCollision(const Location& loc_in)
{
	if (hasPoison[width*loc_in.y + loc_in.x]) {
		hasPoison[width * loc_in.y + loc_in.x] = false;
		return true;
	}
	else {
		return false;
	}
}

void Board::assignPoisonBool(const Location& loc_in)
{
	hasPoison[width * loc_in.y + loc_in.x] = true;
}

void Board::DrawPoison()
{
	for (Location p : poisons) {
		if (p.x >=0 && p.y>=0 && hasPoison[width * p.y + p.x]) {
			//gfx.DrawRectDim(p.x * dimension, p.y * dimension, dimension - 2, dimension - 2, Colors::Yellow);
			DrawCell(p,Colors::Yellow);
		}
	}
}

void Board::initPoisons(Objective& obj)
{
	for (int i = 0; i < width * height; i++) {
		poisons[i].x = -1;
		poisons[i].y = -1;
	}
	for (int i = 0; i < width * height / 4; i++) {
		Location n = { xDist(rng),yDist(rng) };
		if (n == obj.getLocation()) {
			continue;
		}
		else {
			poisons[n.y * width + n.x] = n;
			assignPoisonBool(poisons[n.y * width + n.x]);
		}	
	}
}


