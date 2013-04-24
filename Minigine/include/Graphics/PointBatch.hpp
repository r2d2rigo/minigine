#pragma once

#include <vector>
#include "../Minigine.hpp"
#include "Math/Vector2F.hpp"
#include "Graphics/PointBatchElement.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/GraphicsDevice.hpp"
#include "Graphics/EffectTechnique.hpp"
#include "Graphics/VertexPositionColor.hpp"

using std::vector;
using Minigine::Math::Vector2F;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API PointBatch
		{
		private:
			static const int MaxBatchSize = 2048;
            
			GraphicsDevice graphicsDevice;
			VertexBuffer vertexBuffer;
			IndexBuffer indexBuffer;
			EffectTechnique* technique;
			bool alreadyDrawing;
			vector<PointBatchElement> elements;
			vector<VertexPositionColor> vertices;
			int elementCount;
            
		public:
			PointBatch(const GraphicsDevice& parentDevice);
			~PointBatch();
            
			void Begin() throw(...);
			void Draw(const Vector2F& position, const float& size, const Color& color);
			void End() throw(...);
		};
        
#if _WINDOWS
		MINIGINE_EXPIMP template class MINIGINE_API vector<PointBatchElement>;
#endif
	}
}

