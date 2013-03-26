#include <Game.hpp>

using sf::Event;
using sf::VideoMode;

namespace Minigine
{
	Game::Game()
		: graphicsDevice(800, 600, false)
	{
		this->gameWindow.create(VideoMode(800, 600), std::string());
	}

	void Game::Run()
	{
		while (this->gameWindow.isOpen())
		{
			Event inputEvent;
			while (this->gameWindow.pollEvent(inputEvent))
			{
				if (inputEvent.type == Event::Closed)
				{
					gameWindow.close();
				}
			}

			Update(0.0f);
			Draw(0.0f);

			gameWindow.display();
		}
	}
}