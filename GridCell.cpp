#include "GridCell.h"

namespace Engine 
{
	GridCell::GridCell(int posX, int posY, int alive) : alive(alive)
	{
		newAlive = alive;
		rectangle = *new sf::RectangleShape(sf::Vector2f(_X, _Y));
		alive == 0 ? rectangle.setFillColor(sf::Color::Black) : rectangle.setFillColor(sf::Color::White);
		rectangle.setPosition(posX * _X, posY * _Y);
	}

	

	void GridCell::SetDead()
	{
		newAlive = 0;
	}

	void GridCell::SetAlive()
	{	
		newAlive = 1;
	}

	int GridCell::isAlive()
	{
		return alive;
	}

	void GridCell::SetNewState()
	{
		alive = newAlive;
		alive == 0 ? rectangle.setFillColor(sf::Color::Black) : rectangle.setFillColor(sf::Color::White);
		newAlive = 0;
	}


	sf::RectangleShape GridCell::GetRekt()
	{
		return rectangle;
	}

	GridCell::~GridCell()
	{
		delete &rectangle;
	}
	
}
