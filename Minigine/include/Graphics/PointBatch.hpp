#pragma once

#include <vector>
#include "../Minigine.hpp"
#include "../Math/Vector2F.hpp"
#include "PointBatchElement.hpp"
#include "Color.hpp"
#include "GraphicsDevice.hpp"
#include "EffectTechnique.hpp"
#include "VertexPositionColorSize.hpp"

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
			vector<VertexPositionColorSize> vertices;
			int elementCount;
            
		public:
			PointBatch(const GraphicsDevice& parentDevice);
			~PointBatch();
            
			void Begin() throw(...);
			void Draw(const Vector2F& position, const Color& color, const float& size);
			void End() throw(...);
		};
        
#if _WINDOWS
		MINIGINE_EXPIMP template class MINIGINE_API vector<PointBatchElement>;
#endif
	}
}

