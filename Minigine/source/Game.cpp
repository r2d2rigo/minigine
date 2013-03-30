#include <Game.hpp>

using sf::Event;
using sf::VideoMode;

namespace Minigine
{
	Game::Game(const GraphicsDevice& device)
		: graphicsDevice(device)
	{
		this->gameWindow.create(VideoMode(this->graphicsDevice.GetScreenWidth(), this->graphicsDevice.GetScreenHeight()), std::string());

		// TODO: this should go in GraphicsDevice, but before we need a Window initialized!
		GLenum result = glewInit();
		if (result != GLEW_OK)
		{
			const GLubyte* error = glewGetErrorString(result);
			int b = 0;
		}

		if (GLEW_VERSION_3_0)
		{
			int a = 0;
		}
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