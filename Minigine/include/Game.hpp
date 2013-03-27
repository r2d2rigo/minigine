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
	protected:
		Window gameWindow;
		GraphicsDevice graphicsDevice;

	public:
		const GraphicsDevice& GetGraphicsDevice() const { return this->graphicsDevice; }

	protected:
		Game(const GraphicsDevice& device);

	public:
		void Run();
		virtual void Update(float elapsedTime) = 0;
		virtual void Draw(float elapsedTime) = 0;
	};
}