#include "Graphics/Effect.hpp"

namespace Minigine
{
	namespace Graphics
	{
		void Effect::AddTechnique(string techniqueName, EffectTechnique technique)
		{
			this->techniques[techniqueName] = technique;
		}
	}
}