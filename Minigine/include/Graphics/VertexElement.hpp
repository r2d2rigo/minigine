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
            
        public:
            const VertexElementFormat::VertexElementFormat& GetFormat() const { return this->format; }
            const VertexElementUsage::VertexElementUsage& GetUsage() const { return this->usage; }
            const int& GetUsageIndex() const { return this->usageIndex; }
            const int& GetOffset() const { return this->offset; }
            const int GetSize() const
            {
                switch (this->format)
                {
                    case VertexElementFormat::Float:
                    case VertexElementFormat::Color:
                        return 4;
                    case VertexElementFormat::Vector2F:
                        return 8;
                    case VertexElementFormat::Vector3F:
                        return 12;
                }
            }
            
        public:
            VertexElement(VertexElementFormat::VertexElementFormat elementFormat, VertexElementUsage::VertexElementUsage elementUsage, int elementUsageIndex, int elementOffset) : format(elementFormat), usage(elementUsage), usageIndex(elementUsageIndex), offset(elementOffset)
            {
            };
		};
	}
}