#include <Graphics/GraphicsDevice.hpp>
#include <string.h>
#include "Graphics/VertexPositionColor.hpp"

namespace Minigine
{
	namespace Graphics
	{
		// TODO: support for different GL versions
		GraphicsDevice::GraphicsDevice(int screenWidth, int screenHeight, bool fullScreen)
		{
			this->screenWidth = screenWidth;
			this->screenHeight = screenHeight;
		}

		void GraphicsDevice::SetIndexBuffer(const IndexBuffer& indexBuffer)
		{
			this->indexBuffer = const_cast<IndexBuffer*>(&indexBuffer);
		}

		void GraphicsDevice::SetVertexBuffer(const VertexBuffer& vertexBuffer)
		{
			this->vertexBuffer = const_cast<VertexBuffer*>(&vertexBuffer);
		}

		void GraphicsDevice::Clear(const Color& clearColor)
		{
			glClearColor(clearColor.GetR() / 255.0f, clearColor.GetG() / 255.0f, clearColor.GetB() / 255.0f, clearColor.GetA() / 255.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void GraphicsDevice::Clear(const Color& clearColor, const float& clearDepth)
		{
			glClearColor(clearColor.GetR() / 255.0f, clearColor.GetG() / 255.0f, clearColor.GetB() / 255.0f, clearColor.GetA() / 255.0f);
			glClearDepth(clearDepth);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void GraphicsDevice::Draw() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer->GetHandle());
			glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer->GetHandle());

			glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(VertexPositionColor), 0);
			glVertexAttribPointer(0, 4, GL_UNSIGNED_BYTE, false, sizeof(VertexPositionColor), (void*)(3*4));

			glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, NULL);
		}
	}
}