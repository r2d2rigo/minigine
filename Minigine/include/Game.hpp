#pragma once

#include <SFML/Window.hpp>
#include <../Minigine.hpp>
#include <Graphics/GraphicsDevice.hpp>

using sf::Window;
using Minigine::Graphics::GraphicsDevice;

namespace Minigine
{
	class MINIGINE_API Game
	{
	private:
		Window gameWindow;
		GraphicsDevice graphicsDevice;

	public:
		GraphicsDevice& GetGraphicsDevice() { return this->graphicsDevice; }

	protected:
		Game();

	public:
		void Run();
		virtual void Update(float elapsedTime) = 0;
		virtual void Draw(float elapsedTime) = 0;
	};
}