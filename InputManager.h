#pragma once
#include<SFML\Graphics.hpp>

namespace Engine {

	class InputManager
	{
	public:
		InputManager() {}
		~InputManager(){}
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		bool IsSpriteClicked(sf::Sprite object, sf::Keyboard::Key button, sf::RenderWindow &window);
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};

}