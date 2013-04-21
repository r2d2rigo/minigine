#include <../Minigine.hpp>
#include "Graphics/Texture2D.hpp"
#include "InvalidOperationException.hpp"
#include <../GLConfig.hpp>

namespace Minigine
{
	namespace Graphics
	{
		Texture2D::Texture2D(const GraphicsDevice& graphicsDevice, int textureWidth, int textureHeight, TextureFormat textureFormat)
			: parentDevice(graphicsDevice), width(textureWidth), height(textureHeight), format(textureFormat)
		{
			glGenTextures(1, &this->handle);
		}

		void Texture2D::SetData(const byte data[]) throw(...)
		{
			// TODO: check for correct data size
			//int requiredDataSize = this->width * this->height;

			//switch (this->format)
			//{
			//	case TextureFormat::RGB24:
			//		requiredDataSize *= 3;
			//		break;
			//	case TextureFormat::RGBA32:
			//		requiredDataSize *= 4;
			//		break;
			//	case TextureFormat::DXT1:
			//		requiredDataSize /= 8;
			//		break;
			//	case TextureFormat::DXT5:
			//		requiredDataSize /= 4;
			//		break;
			//}

			//if ((sizeof(data) / sizeof(data[0])) != requiredDataSize)
			//{
			//	throw InvalidOperationException("Data is too large or small for this texture.");
			//}

			glBindTexture(GL_TEXTURE_2D, this->handle);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}

		Texture2D& Texture2D::FromFile(const GraphicsDevice& graphicsDevice, string filename)
		{
			Texture2D newTexture(graphicsDevice, 1, 1);

			return newTexture;
		}
	}
}