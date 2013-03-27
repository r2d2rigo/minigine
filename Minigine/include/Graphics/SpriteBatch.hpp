#pragma once

#include <vector>
#include "../Minigine.hpp"
#include "Math/Vector2F.hpp"
#include "Graphics/BatchElement.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/GraphicsDevice.hpp"
#include "InvalidOperationException.hpp"

using std::vector;
using Minigine::Math::Vector2F;

namespace Minigine
{
	namespace Graphics
	{
		class MINIGINE_API SpriteBatch
		{
		private:
			GraphicsDevice graphicsDevice;

			bool alreadyDrawing;
			vector<BatchElement> elements;
			int elementCount;

		public:
			SpriteBatch(const GraphicsDevice& parentDevice);
			~SpriteBatch();

			void Begin() throw(...);
			void Draw(const Vector2F& position, const Vector2F& size, const Color& color);
			void End() throw(...);
		};

		MINIGINE_EXPIMP template class MINIGINE_API vector<BatchElement>;
	}
}

