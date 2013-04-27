#include "VertexPositionColor.hpp"

namespace Minigine
{
    namespace Graphics
    {
        // TODO: this is ugly...
        VertexElement vpcElements[2] =
        {
            VertexElement(VertexElementFormat::Vector3F, VertexElementUsage::Position, 0, 0),
            VertexElement(VertexElementFormat::Color, VertexElementUsage::Color, 0, sizeof(float) * 3),
        };
        
        const VertexDeclaration& VertexPositionColor::VertexFormat = VertexDeclaration(vector<VertexElement>(vpcElements, vpcElements + 2));
    }
}