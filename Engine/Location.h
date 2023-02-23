#pragma once
struct Location {
	bool operator== (Location l) {
		bool result = l.x == this->x && l.y == this->y;
		return result;
	}
	void add(Location& loc) {
		this->x=x + loc.x;
		this->y =y + loc.y;
	}
	void mult(int a) {
		this->x *= a;
		this->y *= a;
	}
	int x;
	int y;
};