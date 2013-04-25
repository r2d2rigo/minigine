#pragma once

#include <../Minigine.hpp>
#include "VertexElementFormat.hpp"
#include "VertexElementUsage.hpp"

using Minigine::Graphics::VertexElementFormat::VertexElementFormat;
using Minigine::Graphics::VertexElementUsage::VertexElementUsage;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexElement
		{
		private:
			VertexElementFormat::VertexElementFormat format;
			VertexElementUsage::VertexElementUsage usage;
			int usageIndex;
			int offset;
		};
	}
}