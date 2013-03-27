#include <../Minigine.hpp>
#include "Graphics\Texture2D.hpp"
#include <Windows.h>
#include <gl/GL.h>

namespace Minigine
{
	namespace Graphics
	{
		Texture2D::Texture2D(const GraphicsDevice& graphicsDevice, int textureWidth, int textureHeight)
			: parentDevice(graphicsDevice), width(textureWidth), height(textureHeight)
		{
			glGenTextures(1, &this->handle);
		}

		void Texture2D::SetData(const byte data[])
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, this->handle);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
	}
}