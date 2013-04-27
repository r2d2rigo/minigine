#pragma once

#include "../Math/Vector2F.hpp"
#include "Color.hpp"
#include "Texture2D.hpp"

using Minigine::Math::Vector2F;

namespace Minigine
{
	namespace Graphics
	{
		struct PointBatchElement
		{
		public:
			Vector2F Position;
			Color Color;
			float Size;

		public:
			PointBatchElement()
                : Position(Vector2F::Zero), Color(Color::White), Size(0.0f)
			{
			};
		};
	}
}