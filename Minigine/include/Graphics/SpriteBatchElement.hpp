#pragma once

#include "Math/Vector2F.hpp"
#include "Color.hpp"
#include "Texture2D.hpp"

using Minigine::Math::Vector2F;

namespace Minigine
{
	namespace Graphics
	{
		struct SpriteBatchElement
		{
		public:
			Vector2F Position;
			Vector2F Size;
			Color Color;
			Texture2D* Texture;
            float Rotation;

		public:
			SpriteBatchElement()
                : Position(Vector2F::Zero), Size(Vector2F::Zero), Color(Color::White), Texture(NULL), Rotation(0)
			{
			};
		};
	}
}