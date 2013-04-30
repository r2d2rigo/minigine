#include "Graphics/VertexPositionColorTexture.hpp"

namespace Minigine
{
    namespace Graphics
    {
        // TODO: this is ugly...
        VertexElement vpctElements[3] =
        {
            VertexElement(VertexElementFormat::Vector3F, VertexElementUsage::Position, 0, 0),
            VertexElement(VertexElementFormat::Color, VertexElementUsage::Color, 0, sizeof(float) * 3),
            VertexElement(VertexElementFormat::Vector2F, VertexElementUsage::TexCoord, 0, (sizeof(float) * 3) + (sizeof(byte) * 4)),
        };
        
        const VertexDeclaration& VertexPositionColorTexture::VertexFormat = VertexDeclaration(vector<VertexElement>(vpctElements, vpctElements + 3));
    }
}