#include <Graphics/GraphicsDevice.hpp>
#include <string.h>

namespace Minigine
{
	namespace Graphics
	{
		GraphicsDevice::GraphicsDevice(int screenWidth, int screenHeight, bool fullScreen)
		{
			this->screenWidth = screenWidth;
			this->screenHeight = screenHeight;
		}

		void GraphicsDevice::SetIndexBuffer(const IndexBuffer& indexBuffer)
		{
		}

		void GraphicsDevice::SetVertexBuffer(const VertexBuffer& vertexBuffer)
		{
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
		}
	}
}