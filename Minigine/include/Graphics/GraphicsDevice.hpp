#pragma once

#include <../Minigine.hpp>
#include <gl/glew.h>
#include <Windows.h>
#include <gl/GL.h>
#include "Color.hpp"
#include "IndexBuffer.hpp"
#include "VertexBuffer.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API GraphicsDevice
		{
		private:
			int screenWidth;
			int screenHeight;

			IndexBuffer* indexBuffer;
			VertexBuffer* vertexBuffer;

		public:
			const int& GetScreenWidth() const { return this->screenWidth; }
			const int& GetScreenHeight() const { return this->screenHeight; }

			void SetIndexBuffer(const IndexBuffer& indexBuffer);
			void SetVertexBuffer(const VertexBuffer& vertexBuffer);

		public:
			GraphicsDevice(int screenWidth, int screenHeight, bool fullScreen = false);

			void Clear(const Color& clearColor);
			void Clear(const Color& clearColor, const float& clearDepth);
			void Draw() const;
		};
	}
}