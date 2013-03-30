#pragma once

#include <../Minigine.hpp>
#include "Math/Vector3F.hpp"
#include "Graphics/Color.hpp"

using Minigine::Math::Vector3F;
using Minigine::Graphics::Color;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexPositionColor
		{
		public:
			Vector3F Position;
			Color Color;

		public:
			VertexPositionColor();
			VertexPositionColor(const Vector3F& position, const Minigine::Graphics::Color& color);
		};
	}
}