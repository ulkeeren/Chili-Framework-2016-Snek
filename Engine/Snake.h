#pragma once
#include "Board.h"
#include "Location.h"
class Snake {
private:
	class Segment {
	public:
		void InitHead(const Location& loc);
		void InitBody(int active);
		Location GetLoc();
		void MoveBy(Location& delta_loc);
		void Follow(Segment& next);
		void Draw(Board& brd);
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void MoveBy(Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	Location getHead();
	Location direction = { 0,0 };
	bool end = false;
private:
	static constexpr int nSegments = 100;
	Segment segments[nSegments];
	int activeSegments = 0;
	static constexpr Color headColor = Colors::Magenta;
	static constexpr Color bodyColor = Colors::Green;
};