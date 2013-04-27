#pragma once

#include "../Minigine.hpp"
#include "VertexDeclaration.hpp"

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API IVertexType
		{
		public:
			virtual ~IVertexType() { };
			virtual const VertexDeclaration& GetVertexDeclaration() const = 0;
		};
	}
}