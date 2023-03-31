#pragma once
#include "Graphics.h"
#include "Location.h"
#include <random>
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
	int getWidth() const;
	int getHeight() const;
	bool checkPoisonCollision(const Location& loc_in);
	void assignPoisonBool(const Location& loc_in);
	void DrawPoison();
	void initPoisons();
private:
	std::mt19937 rng;
	std::random_device rd;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	static constexpr int dimension = 10;
	static constexpr int width = (Graphics::ScreenWidth)/10;
	static constexpr int height = (Graphics::ScreenHeight)/10;
	bool hasPoison[width * height] = { false };
	Location poisons[width * height];
	Graphics& gfx;
};