#pragma once
#include <vector>
#include"Game.h"
#include<SFML\Graphics.hpp>
#include"DEFINITIONS.h"
namespace Engine
{
	class GridCell
	{
	public:
		GridCell(int posX, int posY, int alive);
		void SetDead();
		void SetAlive();
		int isAlive();
		void SetNewState();
		sf::RectangleShape GetRekt();
		~GridCell();
	private:
		int newAlive = 0;
		int alive = 0;
		sf::RectangleShape rectangle;
		GameDataRef _data;
	};

}
