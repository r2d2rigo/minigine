#pragma once

#include <vector>
#include "../Minigine.hpp"
#include "Math/Vector2F.hpp"
#include "Graphics/BatchElement.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/GraphicsDevice.hpp"
#include "Graphics/Texture2D.hpp"
#include "Graphics/EffectTechnique.hpp"
#include "Graphics/VertexPositionColor.hpp"

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
			vector<BatchElement> elements;
			vector<VertexPositionColor> vertices;
			int elementCount;

		public:
			SpriteBatch(const GraphicsDevice& parentDevice);
			~SpriteBatch();

			void Begin() throw(...);
			void Draw(const Vector2F& position, const Vector2F& size, const Color& color);
			void Draw(const Texture2D& texture, const Vector2F& position, const Color& color);
			void Draw(const Texture2D& texture, const Vector2F& position, const Vector2F& size, const Color& color);
			void End() throw(...);
		};

		MINIGINE_EXPIMP template class MINIGINE_API vector<BatchElement>;
	}
}

