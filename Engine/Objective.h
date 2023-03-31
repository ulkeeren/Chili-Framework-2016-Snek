#pragma once
#include "Location.h"
#include "Colors.h"
#include "Board.h"
#include <random>
class Objective {
private:
	Location loc;
	static constexpr Color c = Colors::Red;	
	void Reassign(Location loc_new) {
		loc = loc_new;
	}
	std::mt19937 rng;
	std::random_device rd;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
public:
	Objective(Location loc_in)
		:
		rng(rd()),
		xDist(0,79),
		yDist(0,59)
	{
		loc = loc_in;
	}
	void Draw(Board& brd) {
		brd.DrawCell(loc,c);
	}
	bool CheckCol(Location loc_snake) {
		if (loc.x == loc_snake.x && loc_snake.y == loc.y

			) {
			Reassign({ xDist(rng),yDist(rng) });
			return true;
		}
		else {
			return false;
		}
	}

	};
class Obstacles {
private:
	static constexpr Color c = Colors::Gray;
	std::mt19937 rng;
	std::random_device rd;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
public:
	Location loc[100];
	int activeLocs = 0;
	Obstacles(Location loc_in)
		:
		rng(rd()),
		xDist(0, 79),
		yDist(0, 59)
	{
		loc[0] = loc_in;
		/*for (int a = 1; a <= 99; a++) {
			loc[a] = { NULL,NULL };
		}*/
	}
	void Draw(Board& brd) {
		for (int a = 0; a < activeLocs + 1; a++) {
			brd.DrawCell(loc[a], c);
		}
	}
	void BuildANew() {
		this->activeLocs++;
		this->loc[activeLocs] = {xDist(rng),yDist(rng)};
	}
	bool CheckCol(Location loc_snake) {
		for (int a=0; a <= activeLocs; a++) {
			if (this->loc[a] == loc_snake)
			{
				return true;
			}
		}
		return false;
	}
};
