#include "GameState.h"
#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"

namespace Engine {
	GameState::GameState(GameDataRef data) :_data(data)
	{

	}
	void GameState::Init()
	{
		this->_data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Game Background"));
		grid = new Grid(_data);
		grid->InitializeCells(_ROWS, _COLS);
	}
	void GameState::HandleInput()
	{
		sf::Event event;
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				this->_data->window.close();
			}
			if (this->_data->input.IsSpriteClicked(_background, sf::Keyboard::A, _data->window))
			{
				pause++;
			}
			if (this->_data->input.IsSpriteClicked(_background, sf::Keyboard::S, _data->window))
			{
				pause = 0;
				grid->RandomizeCellsState();
			}
		}
	}
	void GameState::Update(float dt)
	{
		if (pause > 0)
			Simulate();
	}
	void GameState::Draw(float dt)
	{
		this->_data->window.clear(sf::Color::Green);
		grid->DrawCells();
		this->_data->window.display();
	}
	void GameState::Simulate()
	{
		int neighbours = 0;
		for (int i = 1; i < grid->GetGridCells().size() - 1; i++)
		{

			if (i > _COLS && i < ((_COLS*_ROWS) - _COLS) && i % _COLS != 0 && i % _COLS != (_COLS - 1))
			{
				neighbours = grid->GetGridCells()[i - (_COLS + 1)]->isAlive() + grid->GetGridCells()[i - _COLS]->isAlive() +
					grid->GetGridCells()[i - (_COLS - 1)]->isAlive() + grid->GetGridCells()[i - 1]->isAlive() +
					grid->GetGridCells()[i + 1]->isAlive() + grid->GetGridCells()[i + (_COLS - 1)]->isAlive() +
					grid->GetGridCells()[i + _COLS]->isAlive() + grid->GetGridCells()[i + (_COLS + 1)]->isAlive();


				if ((grid->GetGridCells()[i]->isAlive()) == 0)
				{
					if (neighbours == 3)
					{
						grid->GetGridCells()[i]->SetAlive();

					}

				}
				else
				{

					if (neighbours == 2 || neighbours == 3)
					{
						grid->GetGridCells()[i]->SetAlive();
					}
					else if (neighbours < 2 || neighbours>3) {
						grid->GetGridCells()[i]->SetDead();
					}

				}

			}

		}
		for (int j = 1; j < grid->GetGridCells().size() - 1; j++)
		{
			grid->GetGridCells()[j]->SetNewState();
		}
	}

}
