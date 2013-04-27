#pragma once

#include "../Minigine.hpp"
#include "../Math/Vector3F.hpp"
#include "Color.hpp"

using Minigine::Math::Vector3F;
using Minigine::Graphics::Color;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexPositionColorSize
		{
		public:
			Vector3F Position;
			Color Color;
            float Size;
            
		public:
            VertexPositionColorSize()
                : Position(Vector3F::Zero), Color(Color::White), Size(0.0f)
            {
            }
            
            VertexPositionColorSize(const Vector3F& position, const Minigine::Graphics::Color& color, const float& size)
                : Position(position), Color(color), Size(size)
            {
            }
		};
	}
}