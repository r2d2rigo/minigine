#include "Graphics/SpriteBatch.hpp"
#include "InvalidOperationException.hpp"

namespace Minigine
{
	namespace Graphics
	{
		SpriteBatch::SpriteBatch(const GraphicsDevice& parentDevice)
			: graphicsDevice(parentDevice)
		{
			this->alreadyDrawing = false;
			this->elements = vector<BatchElement>(SpriteBatch::MaxBatchSize);
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

			this->alreadyDrawing = true;
		}

		void SpriteBatch::Draw(const Vector2F& position, const Vector2F& size, const Color& color)
		{
			BatchElement& element = this->elements[this->elementCount];

			element.Position = position;
			element.Size = size;
			element.Color = color;
//			element.Texture = NULL;

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

			++this->elementCount;

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
				// TODO: move to vertex buffers and shaders.
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluOrtho2D(0.0f, this->graphicsDevice.GetScreenWidth(), this->graphicsDevice.GetScreenHeight(), 0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
 
				// TODO: use iterators
				for (int i = 0; i < this->elementCount; ++i)
				{
					BatchElement& currentElement = this->elements[i];

					if (currentElement.Texture != NULL)
					{
						glEnable(GL_TEXTURE_2D);
						glBindTexture(GL_TEXTURE_2D, currentElement.Texture->GetHandle());
					}
					else
					{
						glDisable(GL_TEXTURE_2D);
					}

					glColor4ubv(currentElement.Color.GetVector());
					glBegin(GL_QUADS);
					glVertex2f(currentElement.Position.GetX(), currentElement.Position.GetY());
					glTexCoord2f(0.0f, 0.0f);
					glVertex2f(currentElement.Position.GetX() + currentElement.Size.GetX(), currentElement.Position.GetY());
					glTexCoord2f(1.0f, 0.0f);
					glVertex2f(currentElement.Position.GetX() + currentElement.Size.GetX(), currentElement.Position.GetY() + currentElement.Size.GetY());
					glTexCoord2f(1.0f, 1.0f);
					glVertex2f(currentElement.Position.GetX(), currentElement.Position.GetY() + currentElement.Size.GetY());
					glTexCoord2f(0.0f, 1.0f);
					glEnd();
				}

				this->elementCount = 0;
			}

			this->alreadyDrawing = false;
		}
	}
}