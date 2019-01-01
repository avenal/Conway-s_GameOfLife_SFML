#pragma once
#include<vector>
#include<SFML\Graphics.hpp>
#include"GridCell.h"
#include"Game.h"
#include<iostream>
namespace Engine
{
	class Grid
	{
	public:
		Grid(GameDataRef data);
		void InitializeCells(unsigned int x, unsigned int y);
		void DrawCells();
		void RandomizeCellsState();
		std::vector<GridCell*> GetGridCells();
		~Grid();
	private:
		GameDataRef _data;
		std::vector<GridCell*> cells;
	};
}

