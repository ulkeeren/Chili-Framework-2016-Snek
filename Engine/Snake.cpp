#include "Snake.h"

Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(Location& delta_loc)
{
	for(int a = activeSegments + 1; a >= 1; a--) {
		segments[a].Follow(segments[a-1]);
	}
	segments[0].MoveBy(Location{ delta_loc.x,delta_loc.y});
	for (int a = 1; a < activeSegments + 1; a++) {
		if (segments[a].GetLoc().x == segments[0].GetLoc().x  &&
			segments[a].GetLoc().y == segments[0].GetLoc().y
			) {
			end = true;
		}
	}
}

void Snake::Grow()
{
	this->activeSegments++;
	segments[activeSegments].InitBody(activeSegments);
}

void Snake::Draw(Board& brd)
{
	for (int a = 0; a < this->activeSegments + 1; a++) {
		segments[a].Draw(brd);
	}
}
Location Snake::getHead()
{
	return segments[0].GetLoc();
}	
void Snake::Segment::InitHead(const Location& loc)
{
	this->loc = loc;
	this->c = headColor;
}

void Snake::Segment::InitBody(int active)
{
	Color xc;
	if (active % 2 == 0) {
		xc = { 0,255,0 };
	}
	else {
		xc = { 25,125,25 };
	}
	this->c = xc;
}

Location Snake::Segment::GetLoc()
{
	return this->loc;
}

void Snake::Segment::MoveBy(Location& delta_loc)
{
	this->loc.add(delta_loc);
}

void Snake::Segment::Follow(Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board& brd)
{
	brd.DrawCell(this->loc,this->c);
}
