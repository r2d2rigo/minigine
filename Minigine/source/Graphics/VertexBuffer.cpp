#include <Graphics/VertexBuffer.hpp>
#include "../GLConfig.hpp"

namespace Minigine
{
	namespace Graphics
	{
		VertexBuffer::VertexBuffer(const GraphicsDevice& graphicsDevice, const bool& isDynamic) 
			: Buffer(graphicsDevice, isDynamic)
		{
			glGenBuffers(1, &this->handle);
		}

		void VertexBuffer::SetData(int dataSize, void* data)
		{
			GLenum bufferMode = this->IsDynamic() ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW;

			glBindBuffer(GL_ARRAY_BUFFER, this->handle);
			glBufferData(GL_ARRAY_BUFFER, dataSize, data, bufferMode);
		}
	}
}