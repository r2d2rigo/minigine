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
		class BatchElement
		{
		public:
			Vector2F Position;
			Vector2F Size;
			Color Color;
			Texture2D* Texture;

		public:
			BatchElement()
				: Position(Vector2F::Zero), Size(Vector2F::Zero), Color(Color::White), Texture(NULL)
			{
			};
		};
	}
}