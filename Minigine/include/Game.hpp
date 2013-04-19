#pragma once

#if WINDOWS
#include <SFML/Window.hpp>
using sf::Window;
#endif

#include <../Minigine.hpp>
#include <Graphics/GraphicsDevice.hpp>

using Minigine::Graphics::GraphicsDevice;

namespace Minigine
{
	class MINIGINE_API Game
	{
	protected:
#if WINDOWS
		Window gameWindow;
#else
        
#endif
		GraphicsDevice graphicsDevice;
        static Game* runningInstance;
        
    public:
        // TODO: this singleton has been implemented due to limitations in the application life cycle on iOS.
        //       This should be removed in the future.
        static Game* GetRunningInstance() { return runningInstance; }

	public:
		const GraphicsDevice& GetGraphicsDevice() const { return this->graphicsDevice; }

	protected:
		Game(const GraphicsDevice& device);

	public:
		void Run();
        // TODO: these used to work as pure virtual functions. Why are they getting called now?
        virtual void Initialize() = 0;
		virtual void Update(float elapsedTime) = 0;
		virtual void Draw(float elapsedTime) = 0;
	};
}