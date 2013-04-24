#pragma once

#include "Math/Vector2F.hpp"
#include "Graphics/Color.hpp"
#include "Graphics/Texture2D.hpp"

using Minigine::Math::Vector2F;
using Minigine::Graphics::Color;

namespace Minigine
{
	namespace Graphics
	{
		struct PointBatchElement
		{
		public:
			Vector2F Position;
			float Size;
			Color Color;

		public:
			PointBatchElement()
                : Position(Vector2F::Zero), Size(0.0f), Color(Color::White)
			{
			};
		};
	}
}