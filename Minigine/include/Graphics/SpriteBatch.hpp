#pragma once

#include <vector>
#include "../Minigine.hpp"
#include "Math/Vector2F.hpp"
#include "SpriteBatchElement.hpp"
#include "Color.hpp"
#include "GraphicsDevice.hpp"
#include "Texture2D.hpp"
#include "EffectTechnique.hpp"
#include "VertexPositionColorTexture.hpp"

using std::vector;
using Minigine::Math::Vector2F;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API SpriteBatch
		{
		private:
			static const int MaxBatchSize = 512;

			GraphicsDevice graphicsDevice;
			VertexBuffer vertexBuffer;
			IndexBuffer indexBuffer;
			EffectTechnique* technique;
			bool alreadyDrawing;
			vector<SpriteBatchElement> elements;
			vector<VertexPositionColorTexture> vertices;
			int elementCount;

		public:
			SpriteBatch(const GraphicsDevice& parentDevice);
			~SpriteBatch();

			void Begin() throw(...);
			void Draw(const Vector2F& position, const Vector2F& size, const Color& color);
			void Draw(const Texture2D& texture, const Vector2F& position, const Color& color);
			void Draw(const Texture2D& texture, const Vector2F& position, const Vector2F& size, const Color& color);
            void Draw(const Texture2D& texture, const Vector2F& position, const float& rotation, const Vector2F& size, const Color& color);
			void End() throw(...);
		};

#if _WINDOWS
		MINIGINE_EXPIMP template class MINIGINE_API vector<SpriteBatchElement>;
#endif
	}
}

