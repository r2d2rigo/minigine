#include <math.h>
#include "Graphics/SpriteBatch.hpp"
#include "InvalidOperationException.hpp"
#include "Graphics/VertexPositionColor.hpp"

namespace Minigine
{
	namespace Graphics
	{
		SpriteBatch::SpriteBatch(const GraphicsDevice& parentDevice)
			: graphicsDevice(parentDevice), vertexBuffer(parentDevice, true), indexBuffer(parentDevice, true)
		{
			this->alreadyDrawing = false;
			this->elements = vector<BatchElement>(SpriteBatch::MaxBatchSize);
			this->vertices = vector<VertexPositionColorTexture>(SpriteBatch::MaxBatchSize * 4);
			this->elementCount = 0;
			this->technique = NULL;

            vector<unsigned short> indices;
            for (unsigned short i = 0; i < SpriteBatch::MaxBatchSize; ++i)
            {
                indices.push_back(i * 4);
                indices.push_back((i * 4) + 1);
                indices.push_back((i * 4) + 2);

                indices.push_back((i * 4) + 2);
                indices.push_back((i * 4) + 3);
                indices.push_back(i * 4);
            }
            
            this->indexBuffer.SetData(sizeof(unsigned short) * SpriteBatch::MaxBatchSize * 4, &indices[0]);
            
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
                this->technique = new Minigine::Graphics::EffectTechnique("attribute vec4 position; attribute vec4 color; attribute vec2 texcoord; uniform mat4 world; varying vec4 outcol; varying vec2 outtex; void main() { gl_Position = position * world; outcol = color / 255.0; outtex = texcoord; } ", "precision mediump float; varying vec4 outcol; varying vec2 outtex; uniform sampler2D tex; void main() { gl_FragColor = texture2D(tex, outtex) * outcol; } ");
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
				// TODO: don't clear. Overwrite members.
				this->vertices.clear();

				// TODO: use iterators?
				for (int i = 0; i < this->elementCount; ++i)
				{
					BatchElement& currentElement = this->elements[i];
                    
                    float angleSin = sin(currentElement.Rotation);
                    float angleCos = cos(currentElement.Rotation);
                    
                    Vector2F horzIncrement = Vector2F(currentElement.Size.GetX() * -angleSin, currentElement.Size.GetY() * angleCos);
                    Vector2F vertIncrement = Vector2F(currentElement.Size.GetX() * angleCos, currentElement.Size.GetY() * angleSin);

                    // TODO: check if drawn texture is mirrored
					vertices.push_back(VertexPositionColorTexture(currentElement.Position, currentElement.Color, Vector2F::One));
					vertices.push_back(VertexPositionColorTexture(currentElement.Position + horzIncrement, currentElement.Color, Vector2F::UnitX));
					vertices.push_back(VertexPositionColorTexture(currentElement.Position + horzIncrement + vertIncrement, currentElement.Color, Vector2F::Zero));
					vertices.push_back(VertexPositionColorTexture(currentElement.Position + vertIncrement, currentElement.Color, Vector2F::UnitY));

                    glBindTexture(GL_TEXTURE_2D, currentElement.Texture->GetHandle());
				}

                
				this->technique->Apply();
				this->vertexBuffer.SetData(sizeof(VertexPositionColorTexture) * vertices.size(), &vertices[0]);
				this->graphicsDevice.SetIndexBuffer(this->indexBuffer);
				this->graphicsDevice.SetVertexBuffer(this->vertexBuffer);
				this->graphicsDevice.Draw(this->elementCount * 2);

				this->elementCount = 0;
			}

			this->alreadyDrawing = false;
		}
	}
}