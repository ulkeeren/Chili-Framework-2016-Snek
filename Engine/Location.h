#pragma once
struct Location {
	bool operator== (Location l) {
		bool result = l.x == this->x && l.y == this->y;
		return result;
	}
	void operator=(Location rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
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