#include "Graphics/SpriteBatch.hpp"

namespace Minigine
{
	namespace Graphics
	{
		SpriteBatch::SpriteBatch(const GraphicsDevice& parentDevice)
			: graphicsDevice(parentDevice)
		{
			this->alreadyDrawing = false;
			this->elements = vector<BatchElement>(512);
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
			// TODO: check for vector overflow.
			BatchElement& element = this->elements[this->elementCount];

			element.Position = position;
			element.Size = size;
			element.Color = color;

			++this->elementCount;
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
				// TODO: check for window size.
				glMatrixMode(GL_PROJECTION);
				glLoadIdentity();
				gluOrtho2D(0.0f, 800.0f, 600.0f, 0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
 
				// TODO: use iterators
				for (int i = 0; i < this->elementCount; ++i)
				{
					BatchElement& currentElement = this->elements[i];

					glColor4ubv(currentElement.Color.GetVector());
					glBegin(GL_QUADS);
					glVertex2f(currentElement.Position.GetX(), currentElement.Position.GetY());
					glVertex2f(currentElement.Position.GetX() + currentElement.Size.GetX(), currentElement.Position.GetY());
					glVertex2f(currentElement.Position.GetX() + currentElement.Size.GetX(), currentElement.Position.GetY() + currentElement.Size.GetY());
					glVertex2f(currentElement.Position.GetX(), currentElement.Position.GetY() + currentElement.Size.GetY());
					glEnd();
				}

				this->elementCount = 0;
			}

			this->alreadyDrawing = false;
		}
	}
}