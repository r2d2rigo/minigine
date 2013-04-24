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