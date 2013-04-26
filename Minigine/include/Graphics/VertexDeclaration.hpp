#pragma once

#include <vector>
#include <../Minigine.hpp>
#include "VertexElement.hpp"

using std::vector;
using Minigine::Graphics::VertexElement;

namespace Minigine
{
	namespace Graphics
	{
		struct MINIGINE_API VertexDeclaration
		{
		private:
			int stride;
			vector<VertexElement> elements;
            
        public:
            const int& GetStride() const { return this->stride; }
            const vector<VertexElement>& GetElements() const { return this->elements; }
            
        public:
            VertexDeclaration(const vector<VertexElement>& vertexElements) : elements(vertexElements)
            {
                this->stride = 0;

                for (vector<VertexElement>::const_iterator iter = vertexElements.begin(); iter != vertexElements.end(); ++iter)
                {
                    this->stride += iter->GetSize();
                }
            };
		};
	}
}