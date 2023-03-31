/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "SpriteCodex.h"
#include <chrono>

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(rd()),
	xDist(0, 770),
	yDist(0, 570),
	sxDist(0, 19),
	syDist(0, 19),
	obj({ sxDist(rng),syDist(rng) }),
	obs({ sxDist(rng),syDist(rng) }),
	snek({sxDist(rng),syDist(rng)})
{
	brd.initPoisons();
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	frameTimerCounter += ft.Mark();
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		isBegin = true;
	}
	if (!snek.end && isBegin) {
		if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {//A
			snek.direction = { 1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT)) {//D
			snek.direction = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_UP)) {//W
			snek.direction = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN)) {//S
			snek.direction = { 0,1 };
		}
		if (obj.CheckCol(snek.getHead())) {
			snek.Grow();
			moveRate -= 0.015f;
			obs.BuildANew();
		}
		snek.end = obs.CheckCol(snek.getHead());
		if(frameTimerCounter>moveRate){
			snek.MoveBy(snek.direction);
			frameTimerCounter = 0;
		}
		if (brd.checkPoisonCollision(snek.getHead())) {
			moveRate-= 0.015f;
		}
	}
}

void Game::ComposeFrame()
{
	if (isBegin) {
		snek.Draw(brd);
		obj.Draw(brd);
		brd.DrawBorder();
		obs.Draw(brd);
		brd.DrawPoison();
		if (snek.end) {
			SpriteCodex::DrawGameOver(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2, gfx);
		}
	}
	else {
		SpriteCodex::DrawTitle(gfx.ScreenWidth / 2, gfx.ScreenHeight / 2, gfx);
	}
}
