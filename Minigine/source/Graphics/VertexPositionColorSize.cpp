#include "Graphics/VertexPositionColorSize.hpp"

namespace Minigine
{
    namespace Graphics
    {
        // TODO: this is ugly...
        VertexElement vpcsElements[3] =
        {
            VertexElement(VertexElementFormat::Vector3F, VertexElementUsage::Position, 0, 0),
            VertexElement(VertexElementFormat::Color, VertexElementUsage::Color, 0, sizeof(float) * 3),
            VertexElement(VertexElementFormat::Float, VertexElementUsage::PointSize, 0, (sizeof(float) * 3) + (sizeof(byte) * 4)),
        };        
        
        const VertexDeclaration& VertexPositionColorSize::VertexFormat = VertexDeclaration(vector<VertexElement>(vpcsElements, vpcsElements + 3));
    }
}