#pragma once

#include <../Minigine.hpp>
#include "GraphicsDevice.hpp"
#include "TextureFormat.hpp"

using std::string;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API Texture2D
		{
		private:
			GraphicsDevice parentDevice;
			unsigned int handle;
			int width;
			int height;
			TextureFormat format;

		public:
			const unsigned int& GetHandle() const { return this->handle; }
			const int& GetWidth() const { return this->width; }
			const int& GetHeight() const { return this->height; }
			const TextureFormat& GetFormat() const { return this->format; }
			void SetWidth(const int& textureWidth) { this->width = textureWidth; }
			void SetHeight(const int& textureHeight) { this->height = textureHeight; }

		public:
			Texture2D(const GraphicsDevice& graphicsDevice, int textureWidth, int textureHeight, TextureFormat textureFormat = TextureFormat::RGBA32);
			void SetData(const byte data[]) throw(...);

			static Texture2D& FromFile(const GraphicsDevice& graphicsDevice, string filename);
		};
	}
}
