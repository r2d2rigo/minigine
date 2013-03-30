#pragma once

#include <../Minigine.hpp>
#include "Buffer.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API VertexBuffer : public Buffer
		{
		public:
			void SetData(int dataSize, void* data);

		public:
			VertexBuffer(const GraphicsDevice& graphicsDevice, const bool& isDynamic = false);
		};
	}
}