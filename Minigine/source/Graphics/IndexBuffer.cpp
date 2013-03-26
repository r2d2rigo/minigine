#include <Graphics/IndexBuffer.hpp>
#include <Windows.h>
#include <gl/glew.h>
#include <gl/GL.h>

namespace Minigine
{
	namespace Graphics
	{
		IndexBuffer::IndexBuffer(const bool& isDynamic)
		{
			this->dynamic = isDynamic;
			glGenBuffers(1, &this->handle);
		}

		void IndexBuffer::SetData(int dataSize, void* data)
		{
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, this->GetDynamic() ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);
		}
	}
}