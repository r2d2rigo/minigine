#include <math.h>
#include "Graphics/SpriteBatch.hpp"
#include "InvalidOperationException.hpp"
#include "Graphics/VertexPositionColor.hpp"

namespace Minigine
{
	namespace Graphics
	{
		SpriteBatch::SpriteBatch(const GraphicsDevice& parentDevice)
			: graphicsDevice(parentDevice), vertexBuffer(parentDevice, true), indexBuffer(parentDevice, false)
		{
			this->alreadyDrawing = false;
			this->elements = vector<BatchElement>(SpriteBatch::MaxBatchSize);
			this->vertices = vector<VertexPositionColor>(SpriteBatch::MaxBatchSize * 4);
			this->elementCount = 0;

			this->graphicsDevice = parentDevice;
		}

		SpriteBatch::~SpriteBatch()
		{
		}

		void SpriteBatch::Begin() throw(...)
		{
			if (this->alreadyDrawing)
			{
				throw InvalidOperationException("End must be called before calling Begin again.");
			}
            
            // TODO: this is being lazy loaded right now because we need a valid GL context and we don't have it in the constructor!
            if (this->technique == NULL)
            {
//                this->technique = new Minigine::Graphics::EffectTechnique("layout (location=0) attribute vec3 position; layout (location=1) attribute vec4 color; uniform mat4 world; varying vec4 outcol; void main() { gl_Position = mul(vec4(position, 1.0), world); outcol = color;} ", "varying vec4 outcol; void main() { gl_FragColor = outcol; } ");

                this->technique = new Minigine::Graphics::EffectTechnique("attribute vec3 position; attribute vec4 color; uniform mat4 world; varying vec4 outcol; void main() { gl_Position = vec4(position, 1.0) * world; outcol = color;} ", "varying mediump vec4 outcol; void main() { gl_FragColor = outcol; } ");
            }
            
			this->alreadyDrawing = true;
		}

		void SpriteBatch::Draw(const Vector2F& position, const Vector2F& size, const Color& color)
		{
			BatchElement& element = this->elements[this->elementCount];

			element.Position = position;
			element.Size = size;
			element.Color = color;
			element.Texture = NULL;
            element.Rotation = 0.0f;

			++this->elementCount;

			if (this->elementCount >= this->elements.size())
			{
				this->elements.resize(this->elements.size() * 2);
			}
		}

		void SpriteBatch::Draw(const Texture2D& texture, const Vector2F& position, const Color& color)
		{
			BatchElement& element = this->elements[this->elementCount];

			element.Position = position;
			element.Size = Vector2F(texture.GetWidth(), texture.GetHeight());
			element.Color = color;
			element.Texture = const_cast<Texture2D*>(&texture);

			++this->elementCount;

			if (this->elementCount >= this->elements.size())
			{
				this->elements.resize(this->elements.size() * 2);
			}
		}

		void SpriteBatch::Draw(const Texture2D& texture, const Vector2F& position, const Vector2F& size, const Color& color)
		{
			BatchElement& element = this->elements[this->elementCount];

			element.Position = position;
			element.Size = size;
			element.Color = color;
			element.Texture = const_cast<Texture2D*>(&texture);
            element.Rotation = 0.0f;

			++this->elementCount;

			if (this->elementCount >= this->elements.size())
			{
				this->elements.resize(this->elements.size() * 2);
			}
		}

		void SpriteBatch::Draw(const Texture2D& texture, const Vector2F& position, const float& rotation, const Vector2F& size, const Color& color)
		{
			BatchElement& element = this->elements[this->elementCount];
            
			element.Position = position;
			element.Size = size;
			element.Color = color;
			element.Texture = const_cast<Texture2D*>(&texture);
            element.Rotation = rotation;
            
			++this->elementCount;
            
            // TODO: is this really neccessary?
            this->elements[elementCount] = element;
            
			if (this->elementCount >= this->elements.size())
			{
				this->elements.resize(this->elements.size() * 2);
			}
		}
        
		void SpriteBatch::End() throw(...)
		{
			if (!this->alreadyDrawing)
			{
				throw InvalidOperationException("Begin must be called before calling End.");
			}

			if (this->elementCount > 0)
			{
				int indices[] =
				{
					0, 1, 2,
					2, 3, 0,
					4, 5, 6,
					6, 7, 4,
				};

				// TODO: don't clear. Overwrite members.
				this->vertices.clear();

				// TODO: use iterators
				for (int i = 0; i < this->elementCount; ++i)
				{
					BatchElement& currentElement = this->elements[i];
                    
                    float angleSin = sin(currentElement.Rotation);
                    float angleCos = cos(currentElement.Rotation);
                    
                    Vector2F horzIncrement = Vector2F(currentElement.Size.GetX() * -angleSin, currentElement.Size.GetY() * angleCos);
                    Vector2F vertIncrement = Vector2F(currentElement.Size.GetX() * angleCos, currentElement.Size.GetY() * angleSin);

					vertices.push_back(VertexPositionColor(currentElement.Position, currentElement.Color));
					vertices.push_back(VertexPositionColor(currentElement.Position + horzIncrement, currentElement.Color));
					vertices.push_back(VertexPositionColor(currentElement.Position + horzIncrement + vertIncrement, currentElement.Color));
					vertices.push_back(VertexPositionColor(currentElement.Position + vertIncrement, currentElement.Color));
				}

				this->technique->Apply();
				this->vertexBuffer.SetData(sizeof(VertexPositionColor) * vertices.size(), &vertices[0]);
				this->indexBuffer.SetData(sizeof(int) * 12, &indices[0]);
				this->graphicsDevice.SetIndexBuffer(this->indexBuffer);
				this->graphicsDevice.SetVertexBuffer(this->vertexBuffer	);
				this->graphicsDevice.Draw();

				this->elementCount = 0;
			}

			this->alreadyDrawing = false;
		}
	}
}