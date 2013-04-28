#include <fstream>
#include <../Minigine.hpp>
#include "Graphics/Texture2D.hpp"
#include "InvalidOperationException.hpp"
#include <../GLConfig.hpp>

using std::ifstream;
using std::ios;

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
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
		}

		Texture2D& Texture2D::FromFile(const GraphicsDevice& graphicsDevice, string filename)
		{
            char magicNumber[3];
            unsigned int textureWidth;
            unsigned int textureHeight;
            unsigned int dataSize;
            byte* textureData;
            ifstream inputFile;
            
            inputFile.open(filename.c_str(), ios::in | ios::binary);
            
            if (!inputFile.is_open())
            {
                // throw exception
            }
            
            inputFile.read(&magicNumber[0], sizeof(char) * 3);
            
            // TODO: check for correct header;
            
            inputFile.read(reinterpret_cast<char*>(&textureWidth), sizeof(unsigned int));
            inputFile.read(reinterpret_cast<char*>(&textureHeight), sizeof(unsigned int));
            
            dataSize = textureWidth * textureHeight * 4;
            textureData = new byte[dataSize];
            inputFile.read(reinterpret_cast<char*>(textureData), dataSize);
                        
            inputFile.close();
            
			Texture2D* newTexture = new Texture2D(graphicsDevice, textureWidth, textureHeight, TextureFormat::RGBA32);
            newTexture->SetData(textureData);
            
			return *newTexture;
		}
	}
}