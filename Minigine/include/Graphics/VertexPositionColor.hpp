#pragma once

#include <../Minigine.hpp>
#include "Graphics/IVertexType.hpp"
#include "Math/Vector3F.hpp"
#include "Graphics/Color.hpp"

using Minigine::Math::Vector3F;
using Minigine::Graphics::Color;
using Minigine::Graphics::IVertexType;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexPositionColor : public IVertexType
		{
        private:
            static const VertexDeclaration& declaration;
            
		public:
			Vector3F Position;
			Color Color;

		public:
            VertexPositionColor()
                : Position(Vector3F::Zero), Color(Color::White)
            {
            }
            
            VertexPositionColor(const Vector3F& position, const Minigine::Graphics::Color& color)
                : Position(position), Color(color)
            {
            }
            
            virtual const VertexDeclaration& GetVertexDeclaration() const
            {
                return VertexPositionColor::declaration;
            }
		};
	}
}