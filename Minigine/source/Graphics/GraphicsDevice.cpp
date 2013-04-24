#include <Graphics/GraphicsDevice.hpp>
#include <string.h>
#include "Graphics/VertexPositionColor.hpp"
#include "Graphics/VertexPositionColorTexture.hpp"

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

		void GraphicsDevice::Draw(int primitiveCount) const
		{
//            glEnable(GL_BLEND);
//            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer->GetHandle());
            glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer->GetHandle());
            
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), 0);
            glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(VertexPositionColor), (void*)(sizeof(float) * 3));
//            glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColorTexture), (void*)((sizeof(float) * 3) + (sizeof(byte) * 4)));
            
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
//            glEnableVertexAttribArray(2);
            
//            glDrawElements(GL_TRIANGLES, primitiveCount * 3, GL_UNSIGNED_SHORT, NULL);
            glDrawElements(GL_POINTS, primitiveCount, GL_UNSIGNED_SHORT, NULL);
        }
	}
}