#include <math.h>
#include "Graphics/PointBatch.hpp"
#include "InvalidOperationException.hpp"

namespace Minigine
{
	namespace Graphics
	{
		PointBatch::PointBatch(const GraphicsDevice& parentDevice)
            : graphicsDevice(parentDevice), vertexBuffer(parentDevice, VertexPositionColorSize::VertexFormat, true), indexBuffer(parentDevice, true)
		{
			this->alreadyDrawing = false;
			this->elements = vector<PointBatchElement>(PointBatch::MaxBatchSize);
			this->vertices = vector<VertexPositionColorSize>(PointBatch::MaxBatchSize);
			this->elementCount = 0;
			this->technique = NULL;
            
            vector<unsigned short> indices;
            for (unsigned short i = 0; i < PointBatch::MaxBatchSize; ++i)
            {
                indices.push_back(i);
            }
            
            this->indexBuffer.SetData(sizeof(unsigned short) * PointBatch::MaxBatchSize, &indices[0]);
            
			this->graphicsDevice = parentDevice;
		}
        
		PointBatch::~PointBatch()
		{
		}
        
		void PointBatch::Begin() throw(...)
		{
			if (this->alreadyDrawing)
			{
				throw InvalidOperationException("End must be called before calling Begin again.");
			}
            
            // TODO: this is being lazy loaded right now because we need a valid GL context and we don't have it in the constructor!
            if (this->technique == NULL)
            {
                this->technique = new Minigine::Graphics::EffectTechnique("attribute vec4 position; attribute vec4 color; attribute float size; uniform mat4 world; varying vec4 outcol; varying vec2 outtex; void main() { gl_Position = position * world; outcol = color / 255.0; gl_PointSize = size; } ", "precision mediump float; varying vec4 outcol; void main() { gl_FragColor = outcol; } ");
            }
            
			this->alreadyDrawing = true;
		}
        
		void PointBatch::Draw(const Vector2F& position, const Color& color, const float& size)
		{
			PointBatchElement& element = this->elements[this->elementCount];
            
			element.Position = position;
			element.Size = size;
			element.Color = color;
            
			++this->elementCount;
            
			if (this->elementCount >= this->elements.size())
			{
				this->elements.resize(this->elements.size() * 2);
			}
		}
        
		void PointBatch::End() throw(...)
		{
			if (!this->alreadyDrawing)
			{
				throw InvalidOperationException("Begin must be called before calling End.");
			}
            
			if (this->elementCount > 0)
			{
				// TODO: don't clear. Overwrite members.
				this->vertices.clear();
                
				// TODO: use iterators?
				for (int i = 0; i < this->elementCount; ++i)
				{
					PointBatchElement& currentElement = this->elements[i];
                    
                    // TODO: check if drawn texture is mirrored
					vertices.push_back(VertexPositionColorSize(currentElement.Position, currentElement.Color, currentElement.Size));
				}

				// TODO: non-mobile OpenGL must use glPointSize instead of the shader value!
#if _WINDOWS
				glPointSize(10.0f);
#endif
                
				this->technique->Apply();
				this->vertexBuffer.SetData(sizeof(VertexPositionColorSize) * vertices.size(), &vertices[0]);
				this->graphicsDevice.SetIndexBuffer(this->indexBuffer);
				this->graphicsDevice.SetVertexBuffer(this->vertexBuffer);
				this->graphicsDevice.Draw(this->elementCount);
                
				this->elementCount = 0;
			}
            
			this->alreadyDrawing = false;
		}
	}
}