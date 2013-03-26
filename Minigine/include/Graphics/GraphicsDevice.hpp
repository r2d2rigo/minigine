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
		public:
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