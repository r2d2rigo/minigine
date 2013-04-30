#include "Graphics/IndexBuffer.hpp"
#include <../GLConfig.hpp>
	
namespace Minigine
{
	namespace Graphics
	{
		IndexBuffer::IndexBuffer(const GraphicsDevice& graphicsDevice, const bool& isDynamic)
			: Buffer(graphicsDevice, isDynamic)
		{
			glGenBuffers(1, &this->handle);
		}

		void IndexBuffer::SetData(int dataSize, void* data)
		{
			GLenum bufferMode = this->IsDynamic() ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->handle);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, bufferMode);
		}
	}
}