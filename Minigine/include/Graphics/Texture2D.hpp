#pragma once

#include <../Minigine.hpp>
#include "GraphicsDevice.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API Texture2D
		{
		private:
			unsigned int handle;
			GraphicsDevice parentDevice;
			int width;
			int height;

		public:
			const unsigned int& GetHandle() const { return this->handle; }
			const int& GetWidth() const { return this->width; }
			const int& GetHeight() const { return this->height; }
			void SetWidth(const int& textureWidth) { this->width = textureWidth; }
			void SetHeight(const int& textureHeight) { this->height = textureHeight; }

		public:
			Texture2D(const GraphicsDevice& graphicsDevice, int textureWidth, int textureHeight);
			void SetData(const byte data[]);
		};
	}
}
