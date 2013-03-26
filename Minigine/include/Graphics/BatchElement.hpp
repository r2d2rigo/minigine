#pragma once

#include "Math/Vector2F.hpp"
#include "Graphics/Color.hpp"

using Minigine::Math::Vector2F;
using Minigine::Graphics::Color;

namespace Minigine
{
	namespace Graphics
	{
		struct BatchElement
		{
			Vector2F Position;
			Vector2F Size;
			Color Color;
		};
	}
}