#pragma once

#include <../Minigine.hpp>
#include "Buffer.hpp"
#include "VertexDeclaration.hpp"

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API VertexBuffer : public Buffer
		{
        private:
            const VertexDeclaration& vertexDeclaration;
            
		public:
			void SetData(int dataSize, void* data);
            const VertexDeclaration& GetVertexDeclaration() const { return this->vertexDeclaration; }

		public:
			VertexBuffer(const GraphicsDevice& graphicsDevice, const VertexDeclaration& declaration, const bool& isDynamic = false);
		};
	}
}