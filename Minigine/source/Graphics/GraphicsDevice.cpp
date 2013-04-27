#include <string.h>
#include <Graphics/GraphicsDevice.hpp>
#include "VertexPositionColorSize.hpp"

namespace Minigine
{
	namespace Graphics
	{
		// TODO: support for different GL versions
		GraphicsDevice::GraphicsDevice(int screenWidth, int screenHeight, bool fullScreen)
		{
			this->screenWidth = screenWidth;
			this->screenHeight = screenHeight;
		}

		void GraphicsDevice::SetIndexBuffer(const IndexBuffer& indexBuffer)
		{
			this->indexBuffer = const_cast<IndexBuffer*>(&indexBuffer);
		}

		void GraphicsDevice::SetVertexBuffer(const VertexBuffer& vertexBuffer)
		{
			this->vertexBuffer = const_cast<VertexBuffer*>(&vertexBuffer);
		}

		void GraphicsDevice::Clear(const Color& clearColor)
		{
			glClearColor(clearColor.GetR() / 255.0f, clearColor.GetG() / 255.0f, clearColor.GetB() / 255.0f, clearColor.GetA() / 255.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void GraphicsDevice::Clear(const Color& clearColor, const float& clearDepth)
		{
			glClearColor(clearColor.GetR() / 255.0f, clearColor.GetG() / 255.0f, clearColor.GetB() / 255.0f, clearColor.GetA() / 255.0f);
			glClearDepth(clearDepth);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void GraphicsDevice::Draw(PrimitiveType primitiveType, int primitiveCount) const
		{
//            glEnable(GL_BLEND);
//            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBuffer->GetHandle());
            glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer->GetHandle());
            
            const VertexDeclaration& declaration = this->vertexBuffer->GetVertexDeclaration();
            int vertexStride = declaration.GetStride();
            int primitiveMultiplier;
            
            // TODO: use iterators
            for (int i = 0; i < declaration.GetElements().size(); ++i)
            {
                const VertexElement& currentElement = declaration.GetElements()[i];
                int pointerSize;
                GLenum pointerType;
                int pointerOffset = currentElement.GetOffset();
                
                switch (currentElement.GetFormat())
                {
                    case VertexElementFormat::Vector2F:
                        pointerSize = 2;
                        pointerType = GL_FLOAT;
                        break;
                    case VertexElementFormat::Vector3F:
                        pointerSize = 3;
                        pointerType = GL_FLOAT;
                        break;
                    case VertexElementFormat::Color:
                        pointerSize = 4;
                        pointerType = GL_UNSIGNED_BYTE;
                        break;
                    case VertexElementFormat::Float:
                        pointerSize = 1;
                        pointerType = GL_FLOAT;
                        break;
                }
                
                glVertexAttribPointer(i, pointerSize, pointerType, GL_FALSE, vertexStride, (void*)pointerOffset);
                
                glEnableVertexAttribArray(i);
            }
            
//            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColorSize), 0);
//            glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_FALSE, sizeof(VertexPositionColorSize), (void*)(sizeof(float) * 3));
//            glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColorSize), (void*)((sizeof(float) * 3) + (sizeof(byte) * 4)));
//            
//            glEnableVertexAttribArray(0);
//            glEnableVertexAttribArray(1);
//            glEnableVertexAttribArray(2);
            
            GLenum drawType;
            
            switch (primitiveType)
            {
                case PrimitiveType::PointList:
                    drawType = GL_POINTS;
                    primitiveMultiplier = 1;
                    break;
                    
                case PrimitiveType::TriangleList:
                    drawType = GL_TRIANGLES;
                    primitiveMultiplier = 3;
                    break;
            }
            
            glDrawElements(drawType, primitiveCount * primitiveMultiplier, GL_UNSIGNED_SHORT, NULL);
        }
	}
}