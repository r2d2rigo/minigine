#include <Graphics/VertexBuffer.hpp>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/GL.h>

namespace Minigine
{
	namespace Graphics
	{
		VertexBuffer::VertexBuffer(const bool& isDynamic)
		{
			this->dynamic = isDynamic;
			glGenBuffers(1, &this->handle);
		}

		void VertexBuffer::SetData(int dataSize, void* data)
		{
			glBufferData(GL_ARRAY_BUFFER, dataSize, data, this->IsDynamic() ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		}
	}
}