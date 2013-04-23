#include "Graphics/VertexPositionColorTexture.hpp"

namespace Minigine
{
	namespace Graphics
	{
		VertexPositionColorTexture::VertexPositionColorTexture()
        : Position(Vector3F::Zero), Color(Color::White), TexCoord(Vector2F::Zero)
		{
		}
        
		VertexPositionColorTexture::VertexPositionColorTexture(const Vector3F& position, const Minigine::Graphics::Color& color, const Vector2F& texCoord)
        : Position(position), Color(color), TexCoord(texCoord)
		{
		}
	}
}