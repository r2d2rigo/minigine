#pragma once

#include "../Minigine.hpp"
#include "Buffer.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API IndexBuffer : public Buffer
		{
		public:
			void SetData(int dataSize, void* data);

		public:
			IndexBuffer(const GraphicsDevice& graphicsDevice, const bool& isDynamic = false);
		};
	}
}