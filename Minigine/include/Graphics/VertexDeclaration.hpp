#pragma once

#include <../Minigine.hpp>
#include "VertexElement.hpp"

using Minigine::Graphics::VertexElement;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexDeclaration
		{
		private:
			VertexElement elements;
			int stride;


		};
	}
}