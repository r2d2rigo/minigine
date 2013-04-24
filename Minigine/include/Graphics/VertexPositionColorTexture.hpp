#pragma once

#include <../Minigine.hpp>
#include "Math/Vector3F.hpp"
#include "Graphics/Color.hpp"

using Minigine::Math::Vector2F;
using Minigine::Math::Vector3F;
using Minigine::Graphics::Color;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexPositionColorTexture
		{
		public:
			Vector3F Position;
			Color Color;
            Vector2F TexCoord;
            
		public:
			VertexPositionColorTexture();
			VertexPositionColorTexture(const Vector3F& position, const Minigine::Graphics::Color& color, const Vector2F& texCoord);
		};
	}
}