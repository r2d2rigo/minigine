#include <Game.hpp>

#if _WINDOWS
using sf::Event;
using sf::VideoMode;

namespace Minigine
{
	Game* Game::runningInstance = NULL;

	Game::Game(const GraphicsDevice& device)
		: graphicsDevice(device)
	{
        Game::runningInstance = this;
        
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
		this->Initialize();

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

            // TODO: get a correct timestep
			Update(0.0f);
			Draw(0.0f);

			gameWindow.display();
		}
	}
}
#endif

// TODO: don't create a whole file for each platform!
#if IOS
#import "AppDelegate.hpp"

namespace Minigine
{
    Game* Game::runningInstance = nil;
    
    Game::Game(const GraphicsDevice& device)
        : graphicsDevice(device)
    {
    }
    
    void Game::Run()
    {
        @autoreleasepool
        {
            UIApplicationMain(0, nil, nil, NSStringFromClass([AppDelegate class]));
        }
    }
}
#endif