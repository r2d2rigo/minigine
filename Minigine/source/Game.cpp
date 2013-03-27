#include <Game.hpp>

using sf::Event;
using sf::VideoMode;

namespace Minigine
{
	Game::Game(const GraphicsDevice& device)
		: graphicsDevice(device)
	{
		this->gameWindow.create(VideoMode(this->graphicsDevice.GetScreenWidth(), this->graphicsDevice.GetScreenHeight()), std::string());
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