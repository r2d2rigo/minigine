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
			glBindTexture(GL_TEXTURE_2D, this->handle);
			glTexImage2D(GL_TEXTURE_2D, 1, GL_RGB, this->width, this->height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
	}
}