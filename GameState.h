#pragma once
#include <SFML\Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Grid.h"
namespace Engine {
	class GameState :public State
	{
	public:
		GameState(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);
		void Simulate();
	private:
		GameDataRef _data;
		
		sf::Sprite _background;
		Grid *grid;
		int pause=0;
	};
}