#include "Graphics/VertexPositionColor.hpp"

namespace Minigine
{
	namespace Graphics
	{
		VertexPositionColor::VertexPositionColor() 
			: Position(Vector3F::Zero), Color(Color::White)
		{
		}

		VertexPositionColor::VertexPositionColor(const Vector3F& position, const Minigine::Graphics::Color& color)
			: Position(position), Color(color)
		{
		}
	}
}