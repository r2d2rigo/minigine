#pragma once

#include "../Minigine.hpp"
#include "../Math/Vector3F.hpp"
#include "Color.hpp"
#include "VertexDeclaration.hpp"

using Minigine::Math::Vector3F;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexPositionColor
		{
        public:
            const static VertexDeclaration& VertexFormat;
            
		public:
			Vector3F Position;
			Color Color;

		public:
            VertexPositionColor()
                : Position(Vector3F::Zero), Color(Color::White)
            {
            }
            
            VertexPositionColor(const Vector3F& position, const Minigine::Graphics::Color& color)
                : Position(position), Color(color)
            {
            }
		};
	}
}